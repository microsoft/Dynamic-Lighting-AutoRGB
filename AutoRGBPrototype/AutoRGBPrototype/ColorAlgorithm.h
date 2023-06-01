#pragma once

#include "ShaderDefines.h"
#include <Vector3.h>

class ColorAlgorithm
{
public:
    ColorAlgorithm() {}
    ~ColorAlgorithm() {}

    void Initialize(int numPixels);

    Vector3 CalculatePredominantColor(uint32_t* shaderOutput);

private:
    void ClearStatistics();
    Vector3 CalculateAverageColor(uint32_t* shaderOutput);
    Vector3 CalculateColorFromTopBins();

    int m_numPixels;
    float m_avgBins[NUM_HISTOGRAMS]{};
    std::vector<uint32_t> m_histograms[NUM_HISTOGRAMS]{};
};