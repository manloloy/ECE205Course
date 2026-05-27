# Lab 02F: Pointer-Based Image Processing

## Objective

Practice 2D data manipulation using 1D pointers and flattened arrays. Students will implement basic image filters by treating a single-dimensional array as a 2D grid.

- Understand the relationship between 2D coordinates `(x, y)` and 1D memory indices.
- Practice pointer arithmetic to traverse and modify data without using square brackets.
- Implement conditional logic for pixel manipulation (Thresholding and Capping).

## Background

In graphics programming, a 2D image is often stored in a 1D array to ensure all pixel data is contiguous in memory. To access a pixel at row `y` and column `x` in an image of a specific `width`, use the formula:

`index = (y * width) + x`

A grayscale pixel value is an integer between 0 (black) and 255 (white).

## Task

Write a program that simulates a 10x10 grayscale image using a 1D array of 100 integers. Implement the following filters **using only pointer arithmetic** (do not use `[]` inside the filter functions):

1.  **Inversion Filter:** Every pixel `p` becomes `255 - p`.
2.  **Brightness Filter:** Add a user-defined value to every pixel. If the result exceeds 255, it must be capped at 255.
3.  **Threshold Filter:** If a pixel is greater than a user-defined threshold, set it to 255. Otherwise, set it to 0.

## Input

- An integer for the brightness adjustment.
- An integer for the threshold value (0-255).

## Sample Output
Original Image (Gradient):
0 2 4 6 8 10 12 14 16 18
20 22 24 26 28 30 32 34 36 38
...

Inverted Image:
255 253 251 249 247 245 243 241 239 237
235 233 231 229 227 225 223 221 219 217
...

After Thresholding (T=128):
0 0 0 0 0 0 0 0 0 0
...
255 255 255 255 255 255 255 255 255 255

## C++ Template

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

// TODO: Implement Inversion using pointer arithmetic (e.g., *(ptr + i))
void InvertFilter(int* image, int size) {
}

// TODO: Implement Brightness using pointer arithmetic. Cap values at 255.
void BrightnessFilter(int* image, int size, int adjustment) {
}

// TODO: Implement Threshold using the (y * width + x) index logic with pointers
void ThresholdFilter(int* image, int width, int height, int threshold) {
}

void PrintImage(int* image, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cout << setw(4) << *(image + (y * width + x));
        }
        cout << endl;
    }
}

int main() {
    const int W = 10;
    const int H = 10;
    int image[W * H];

    // Initialize with a simple gradient
    for (int i = 0; i < W * H; ++i) {
        image[i] = i * 2;
    }

    int brightness, threshold;
    cout << "Enter brightness adjustment: ";
    cin >> brightness;
    cout << "Enter threshold (0-255): ";
    cin >> threshold;

    cout << "\nOriginal Image:\n";
    PrintImage(image, W, H);

    InvertFilter(image, W * H);
    cout << "\nInverted Image:\n";
    PrintImage(image, W, H);

    BrightnessFilter(image, W * H, brightness);
    cout << "\nAfter Brightness Adjustment:\n";
    PrintImage(image, W, H);

    ThresholdFilter(image, W, H, threshold);
    cout << "\nAfter Thresholding:\n";
    PrintImage(image, W, H);

    return 0;
}
