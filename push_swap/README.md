# push_swap

(code to be recovered)

Push swap is a sorting algorithm where the user provides a list of numbers. This list is interpreted as a stack and it needs to be sorted using a specific set of instructions. There's a second stack avaiable to help sorting the original stack. Instructions are printed to stdout.

## General Requirements  

- Must follow the [Norminette](https://github.com/42School/norminette) style guide.
- Only read, write, malloc, free, exit allowed.
- Projects should not have memory leaks or terminate unexpectedly.
- Must submit a Makefile with specified rules that compiles the program.

## Requirements

The stacks are named `a` and `b`. At first, the stack `b` is empty and `a` contains a random amount of unrepeated `int`s.

Stack `a` must end up sorted in ascending order using instructions from the instruction set.

### Instructions

- **sa** - Swap the first 2 elements of the stack `a`
- **sb** - Swap the first 2 elements of the stack `b`
- **ss** - `sa` + `sb`
- **pa** - Push the first element of `b` to the top of `a`
- **pb** - Push the first element of `a` to the top of `b`
- **ra** - Shift all elements of stack `a` by one, upwards
- **rb** - Shift all elements of stack `b` by one, upwards
- **rr** - `rb` + `ra`
- **rra** - `ra` reversed
- **rrb** - `rb` reversed
- **rrr** - `rra` + `rrb`

The goal is to sort the stack in the least amount of movements. The program should short 100 random numbers in less than 700 instructions and 500 random numbers in 5500 intructions.

# Checker

Checker is a program that takes a list of numbers as an input, then reads a set of instructions provided in STDIN. The program displays `OK`, `KO` or `Error` if the stack is sorted, not sorted or there was a rare input.
