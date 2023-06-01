#pragma once

#define NUM_BINS_PER_HISTOGRAM		8
#define NUM_HISTOGRAMS				3											// To represent the RGB color space
#define NUM_BINS					NUM_BINS_PER_HISTOGRAM * NUM_HISTOGRAMS
#define VALUES_PER_BIN				256 / NUM_BINS_PER_HISTOGRAM				// Create 8 bins for each histogram, with each one having a range of 32. Each pixel from the capture texture will be placed into a bin.

#define HISTOGRAM_OFFSET_0			0											// Where the R histogram starts in the array outputted by the shader
#define HISTOGRAM_OFFSET_1          NUM_BINS_PER_HISTOGRAM						// Where the G histogram starts in the array outputted by the shader
#define HISTOGRAM_OFFSET_2          2 * NUM_BINS_PER_HISTOGRAM					// Where the B histogram starts in the array outputted by the shader
