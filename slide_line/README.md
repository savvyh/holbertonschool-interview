# 2048 (single line)

## Description
This project implements a simplified version of the 2048 game, focusing on sliding and merging mechanics for a single line. The goal is to create a function that slides and merges numbers in a line, either to the left or right, following the rules of the 2048 game.

## Requirements 💻
- All files should end with a new line
- Use Betty style
- No more than 5 function per file
- The prototypes of all functions should be included in the header file called `slide_line.h`
- Execute : `gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-slide_line.c -o 0-slide_line`

## Example 🔢
Initial line: [2, 2, 0, 2]

Sliding left:
- Numbers slide: [2, 2, 2, 0]
- Merging: [4, 2, 0, 0]

Sliding right:
- Numbers slide: [0, 0, 2, 4]
- No further merging possible

## Task 🚀
Only one task for this project :  reproduce the 2048 game mechanics on a single horizontal line.
Given an array of integers, we want to be able to slide & merge it to the left or to the right. Identical numbers, if they are contiguous or separated by zeros, should be merged

## Author : 
Sarah Boutier
