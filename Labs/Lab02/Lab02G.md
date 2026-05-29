# Lab 02G: Real-World Image Filtering

## Objective
Apply the pointer arithmetic and image filtering logic from Lab 02F to a real grayscale image file.

- Practice loading and saving external assets.
- Adapt existing logic to different data types (`int` to `unsigned char`).
- Verify algorithmic correctness through visual feedback.

## Background
In Lab 02F, you simulated an image using a small integer array. In this lab, you will use the `stb_image` library to load a real `.jpg` or `.png` file into memory. The library provides a pointer to a contiguous block of memory where each byte (`unsigned char`) represents a pixel value from 0 to 255.

## Task
1. Download `stb_image.h` and `stb_image_write.h` into your project folder. In the same directory as your Lab02G.cpp program run the following commands to download the needed header files for image read and write.
```bash
wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
wget https://raw.githubusercontent.com/nothings/stb/master/stb_image_write.h
```
or you can download directly from the required_files folder that should be in the same directory as this Lab (ECE205Course/Labs/Lab02/required_files)
2. Use the provided template to load `input.jpg`. The required_files directory has some test grayscale images you can use. Either change the input.jpg to <nameofimage>.jpg or rename the images to input.jpg to test your program.
3. Port your `InvertFilter`, `BrightnessFilter`, and `ThresholdFilter` functions from Lab 02F. 
4. **Note:** You must change the parameter types from `int*` to `unsigned char*`.
5. Run the filters on the real image and save the result as `output.jpg`.

## C++ Template

```cpp
#include <iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

// TODO: Port InvertFilter from 02F (Change int* to unsigned char*)
void InvertFilter(unsigned char* image, int size) {
}

// TODO: Port BrightnessFilter from 02F (Handle unsigned char overflow)
void BrightnessFilter(unsigned char* image, int size, int adjustment) {
}

// TODO: Port ThresholdFilter from 02F
void ThresholdFilter(unsigned char* image, int width, int height, int threshold) {
}

int main() {
    string inputPath = "input.jpg";
    int width, height, channels;

    // Load image as 1-channel (Grayscale)
    unsigned char* img = stbi_load(inputPath.c_str(), &width, &height, &channels, 1);

    if (img == nullptr) {
        cout << "Failed to load image. Ensure input.jpg is in the directory." << endl;
        return 1;
    }

    int size = width * height;

    // Apply your functions
    InvertFilter(img, size);
    BrightnessFilter(img, size, 30);
    ThresholdFilter(img, width, height, 128);

    // Save result
    stbi_write_jpg("output.jpg", width, height, 1, img, 100);

    cout << "Processed image saved to output.jpg" << endl;

    stbi_image_free(img);
    return 0;
}
