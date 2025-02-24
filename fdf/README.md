# FdF

(Code to be recovered)

This programs creates a wireframe model from a file, representing a 3D landscape.

A graphics library whose task is to paint points on a window is provided.

## General Requirements  

- Must follow the [Norminette](https://github.com/42School/norminette) style guide.
- Allowed functions: open, close, read, write, malloc, free, perror, strerror, exit, math library, MiniLibX graphics library
- Projects should not have memory leaks or terminate unexpectedly.
- Must submit a Makefile with specified rules that compiles the program.

## Requirements

- The model is represented as an isometric projection (+).
- The source file is a numeric grid where each number poisition represent its floor-coordinates and the number is the height.
- The program has rotation, translation and zoom with keybinds.
- Program arguments include color in hexadecimal format and projection distortion (Obliques projection)
