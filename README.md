# Interest Finder

![License](https://img.shields.io/github/license/zS1L3NT/cpp-interest-finder?style=for-the-badge) ![Languages](https://img.shields.io/github/languages/count/zS1L3NT/cpp-interest-finder?style=for-the-badge) ![Top Language](https://img.shields.io/github/languages/top/zS1L3NT/cpp-interest-finder?style=for-the-badge) ![Commit Activity](https://img.shields.io/github/commit-activity/y/zS1L3NT/cpp-interest-finder?style=for-the-badge) ![Last commit](https://img.shields.io/github/last-commit/zS1L3NT/cpp-interest-finder?style=for-the-badge)

Interest Finder is a script meant to find Simple and Compund Interest using the equations taught in the GCE O level Syllabus.

## Motivation

I wanted to try using C++ in a project because it seemed like a good language to learn. In math class, I used to learn about Simple and Compund Interest but using the formulas they taught in class was quite tiring. Using this script, I can calculate any unknown in the formulas by passing in value for all other unknowns.

## Features

-   Find any of the unknowns in the following equations by passing in values for all other unknowns
    -   Simple Interest - `I = (P × R × T) / 100`
    -   Compund Interest - `A = P(1 + r/100) ^ n`

## Usage

Using `g++`

```
$ g++ interest.cpp -o interest && interest
```

will output an executable file called `interest` and run the file

If you cannot compile the C++ then use the .exe file given.

## Built with

-   C++
