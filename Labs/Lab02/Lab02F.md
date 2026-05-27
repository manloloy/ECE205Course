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
