# Lab 02G: Real Image Processing with Pointers

## Objective
Move from simulated data to processing a real grayscale image file. You will use pointers to manipulate raw pixel data from a JPG or PNG file.

## Task
1. Load a real image file using the `stb_image` library.
2. Convert the image to grayscale (if it isn't already).
3. Implement Inversion, Brightness, and Threshold filters using **raw pointer arithmetic**.
4. Save the modified image back to disk.

## Implementation Details
You will work with a pointer of type `unsigned char*`. Each element represents one pixel (0-255).

```cpp
#include <iostream>

// Libraries for reading and writing images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

// TODO: Implement Inversion using pointer arithmetic
void InvertFilter(unsigned char* data, int size) {
    for (int i = 0; i < size; ++i) {
        // Your logic here using *(data + i)
    }
}

// TODO: Implement Brightness. Handle overflow (cap at 255).
void BrightnessFilter(unsigned char* data, int size, int adjustment) {
    for (int i = 0; i < size; ++i) {
        int val = *(data + i) + adjustment;
        *(data + i) = (val > 255) ? 255 : (val < 0 ? 0 : (unsigned char)val);
    }
}

// TODO: Implement Threshold using y * width + x indexing
void ThresholdFilter(unsigned char* data, int width, int height, int threshold) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char* pixel = data + (y * width + x);
            *pixel = (*pixel > threshold) ? 255 : 0;
        }
    }
}

int main() {
    string filename = "input.jpg";
    int width, height, channels;

    // Load image as Grayscale (1 channel)
    unsigned char* img = stbi_load(filename.c_str(), &width, &height, &channels, 1);

    if (img == NULL) {
        cout << "Error: Could not load image. Make sure input.jpg is in the folder." << endl;
        return 1;
    }

    int size = width * height;

    // Apply Filters
    InvertFilter(img, size);
    BrightnessFilter(img, size, 50);
    ThresholdFilter(img, width, height, 128);

    // Save Output
    stbi_write_jpg("output.jpg", width, height, 1, img, 100);

    cout << "Image processed and saved as output.jpg" << endl;

    stbi_image_free(img);
    return 0;
}
