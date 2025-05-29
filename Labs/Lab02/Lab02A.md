# Lab 02A: Removing Non-Alphabetic Characters Using `for` Loops

## Objective

In this lab, you will write a program that **removes all non-alphabetic characters** from an input string. This exercise is designed to reinforce your understanding of **`for` loops**, character handling, and string traversal in both **C and C++**.

---

## Problem Description

Given a line of input, your program should **output only the alphabetic characters**, preserving their order. All spaces, punctuation, digits, and other symbols should be removed.

### Example

#### Input:
```
-Hello, 1 world$!
```

#### Output:
```
Helloworld
```

---

## Requirements

- Use a `for` loop to traverse the string or character array.
- In C++, you may use the `string` class.
- In C, you will work with character arrays.
- You **must** use the `isalpha()` function to test whether a character is alphabetic. This function is available through:
  - `<cctype>` in C++
  - `<ctype.h>` in C

---

## Notes

- Use `getline()` to read the full input string in C++. For C, use `fgets()` or similar.
- Be mindful of newline characters that `fgets()` may store.
- You may construct a new string or character array to store the alphabetic characters only.

---

## Recommended Functions and Headers

| Language | Function/Feature | Purpose                          |
|----------|------------------|----------------------------------|
| C++      | `getline(cin, str)` | Read full line of input      |
| C++      | `isalpha(c)`     | Returns true if `c` is alphabetic |
| C++      | `string.at(i)`   | Access character at index `i`   |
| C++      | `string += char` | Append character to string      |
| C        | `fgets()`        | Read input including spaces      |
| C        | `isalpha()`      | Test if character is alphabetic |
| C        | `putchar()`      | Output single character         |

---

## Sample Run

#### Input:
```
My #1 pick: C++
```

#### Output:
```
MypickC
```

---

