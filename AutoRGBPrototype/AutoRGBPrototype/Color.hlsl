#include "ShaderHelpers.hlsli"

// This is the histogram that we will pass back to the app through the UAV
RWBuffer<uint> FinalHistogram : register(u0);

// This is the screen capture that is passed in as a 2D texture through the SRV
Texture2D<unorm float4> InputTexture : register(t0);

// We need the width of the texture to go through each pixel
cbuffer ScreenWidth : register(b0)
{
	uint Width;
};

// We will calculate a histogram for each group and store it in the Local Data Share
groupshared uint GroupHistogram[NUM_BINS];

[numthreads(NUM_BINS, 1, 1)]
void main(uint3 DTid : SV_DispatchThreadID, uint3 GroupId : SV_GroupID, uint3 GTid : SV_GroupThreadID)
{
	// Clear the local group histogram buffer
	if (GTid.x < NUM_BINS)
	{
		GroupHistogram[GTid.x] = 0;
	}

	// Blocks execution of all threads in a group until all group shared accesses have been completed
	GroupMemoryBarrierWithGroupSync();

	// Go through each pixel and create a histogram for each group
	for (uint i = GTid.x; i < Width; i += NUM_BINS)
	{
		uint2 pixelPosition = uint2(i, GroupId.x);
		float4 pixel = InputTexture.Load(uint3(pixelPosition, 0));

		uint3 binnedRGBValues = GetRGBBinned(pixel.xyz);

		InterlockedAdd(GroupHistogram[HISTOGRAM_OFFSET_0 + binnedRGBValues.r], 1);
		InterlockedAdd(GroupHistogram[HISTOGRAM_OFFSET_1 + binnedRGBValues.g], 1);
		InterlockedAdd(GroupHistogram[HISTOGRAM_OFFSET_2 + binnedRGBValues.b], 1);
	}

	GroupMemoryBarrierWithGroupSync();

	// Add the local group histogram to the final histogram
	InterlockedAdd(FinalHistogram[GTid.x], GroupHistogram[GTid.x]);
}