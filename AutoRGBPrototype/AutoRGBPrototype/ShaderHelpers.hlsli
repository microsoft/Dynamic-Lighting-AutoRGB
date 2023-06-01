#include "ShaderDefines.h"

uint3 GetRGBBinned(float3 c)
{
	uint3 color = uint3(floor(c * 255.0f));
	uint valuesPerBin = 256 / NUM_BINS_PER_HISTOGRAM;
	return color / valuesPerBin;
}