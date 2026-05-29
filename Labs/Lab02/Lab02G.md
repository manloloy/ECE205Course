```cpp
#include <iostream>
#include <string>

// Preprocessor defines for stb libraries (only in one source file)
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

/**
 * Inverts the grayscale image.
 * Uses pointer arithmetic: *(image + i)
 */
void InvertFilter(unsigned char* image, int size) {
    for (int i = 0; i < size; ++i) {
        *(image + i) = 255 - *(image + i);
    }
}

/**
 * Adjusts brightness of the image.
 * Capped at 255 to prevent overflow.
 */
void BrightnessFilter(unsigned char* image, int size, int adjustment) {
    for (int i = 0; i < size; ++i) {
        int currentVal = *(image + i);
        int newVal = currentVal + adjustment;

        // Manual Clamping
        if (newVal > 255) newVal = 255;
        if (newVal < 0) newVal = 0;

        *(image + i) = (unsigned char)newVal;
    }
}

/**
 * Converts image to black and white based on threshold.
 * Uses y * width + x indexing with pointers.
 */
void ThresholdFilter(unsigned char* image, int width, int height, int threshold) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char* pixel = image + (y * width + x);
            if (*pixel > threshold) {
                *pixel = 255;
            } else {
                *pixel = 0;
            }
        }
    }
}

int main() {
    string inputFilename = "input.jpg";
    string outputFilename = "output.jpg";
    int width, height, channels;

    // 1. Load the image. We force the 5th argument to '1' to ensure it loads as Grayscale.
    unsigned char* img = stbi_load(inputFilename.c_str(), &width, &height, &channels, 1);

    if (img == nullptr) {
        cout << "Error: Could not load " << inputFilename << ". Ensure the file exists." << endl;
        return 1;
    }

    cout << "Loaded Image: " << width << "x" << height << endl;

    // 2. Get User Input
    int brightness, threshold;
    cout << "Enter brightness adjustment (e.g., 50 or -50): ";
    cin >> brightness;
    cout << "Enter threshold value (0-255): ";
    cin >> threshold;

    int totalPixels = width * height;

    // 3. Apply Filters
    // Note: We apply them sequentially to the same data block
    cout << "Applying Inversion..." << endl;
    InvertFilter(img, totalPixels);

    cout << "Applying Brightness..." << endl;
    BrightnessFilter(img, totalP

```
