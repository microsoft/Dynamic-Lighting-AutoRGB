#include "pch.h"
#include "ColorAlgorithm.h"

void ColorAlgorithm::Initialize(int numPixels)
{
    m_numPixels = numPixels;
}

// Clear all previously calculated statistics
void ColorAlgorithm::ClearStatistics()
{
    for (uint32_t histogram = 0; histogram < NUM_HISTOGRAMS; histogram++)
    {
        m_avgBins[histogram] = 0.0f;
        m_histograms[histogram].clear();
    }
}

// Calculate the weighted average of the histogram outputted by the shader
Vector3 ColorAlgorithm::CalculateAverageColor(uint32_t* shaderOutput)
{
    ClearStatistics();

    float numPixelsPerHistogram[NUM_HISTOGRAMS] = {};

    // Iterate through the 3 calculated histograms (R, G, and B) 
    for (uint32_t histogram = 0; histogram < NUM_HISTOGRAMS; histogram++)
    {
        auto& currHistogram = m_histograms[histogram];
        currHistogram.resize(NUM_BINS_PER_HISTOGRAM);

        uint32_t const offset = histogram * NUM_BINS_PER_HISTOGRAM;
        for (uint32_t bin = 0; bin < NUM_BINS_PER_HISTOGRAM; bin++)
        {
            uint32_t numPixelsInBin = shaderOutput[offset + bin];
            currHistogram[bin] = numPixelsInBin;

            m_avgBins[histogram] += bin * (numPixelsInBin / m_numPixels);
            numPixelsPerHistogram[histogram] += numPixelsInBin;
        }
    }

    Vector3 avgColor;
    uint8_t c1 = 0, c2 = 0, c3 = 0;
    c1 = static_cast<uint8_t>(min(m_avgBins[0] * VALUES_PER_BIN, 255.0f));
    c2 = static_cast<uint8_t>(min(m_avgBins[1] * VALUES_PER_BIN, 255.0f));
    c3 = static_cast<uint8_t>(min(m_avgBins[2] * VALUES_PER_BIN, 255.0f));

    avgColor = Vector3(c1, c2, c3) / 255.0f;
    avgColor.Normalize();

    return avgColor;
}

// Calculate the color from the top X bins in the histograms.
// Start with the highest bin of each histogram. 
// If the number of pixels in that bin meets the required pixel coverage, 
// then only that bin will be used to calculate the color. 
// Otherwise, we add the next highest bin and so on until we meet the required pixel coverage.
Vector3 ColorAlgorithm::CalculateColorFromTopBins()
{
    float sumOfTopXBins[NUM_HISTOGRAMS] = {};

    uint32_t pixelCoverage = 0;
    uint32_t numBinsUsed = 0;

    // Percentage of pixels required before we stop adding buckets
    float percentPixelsRequired = 0.7f;

    // Prevent one color overly dominating the rest
    float binDisplacementValue = 0.025f;

    // Iterate through the top X bins in each histogram until we have met the required pixel coverage
    for (int bin = NUM_BINS_PER_HISTOGRAM - 1; bin >= 0; bin--)
    {
        float threshold = percentPixelsRequired * m_numPixels;
        if (pixelCoverage > threshold)
        {
            break;
        }

        numBinsUsed++;
        for (uint32_t histogram = 0; histogram < NUM_HISTOGRAMS; ++histogram)
        {
            uint32_t numPixelsInBin = m_histograms[histogram][static_cast<uint32_t>(bin)];

            sumOfTopXBins[histogram] += numPixelsInBin * (bin + binDisplacementValue);
            pixelCoverage += numPixelsInBin;
        }
    }

    // Create a color based on the sum of the top X bins from the R, G, and B histograms.
    Vector3 color = Vector3(sumOfTopXBins[0], sumOfTopXBins[1], sumOfTopXBins[2]);
    color.Normalize();

    return color;
}

// Calculate the predominant color on the screen.
// Use a mix between the average color and the color from the top bins.
Vector3 ColorAlgorithm::CalculatePredominantColor(uint32_t* shaderOutput)
{
    Vector3 avgColor = CalculateAverageColor(shaderOutput);
    Vector3 topXBinsColor = CalculateColorFromTopBins();

    float alpha = 0.4f;
    Vector3 finalColor = (1.0f - alpha) * topXBinsColor + alpha * avgColor;

    return finalColor;
}