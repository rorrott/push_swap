# push_swap

push_swap is a sorting algorithm project developed as part of the 42 School curriculum.

The goal is to sort a stack of integers using a limited set of stack operations, with the challenge of minimizing the total number of moves.

This project focuses on algorithm design, complexity optimization, and data structure manipulation in C.

## Features

- Input: A list of integers as program arguments

- Output: A sequence of operations that sorts the numbers in ascending order

Available operations:

- sa / sb → swap top two elements of stack A or B

- ss → swap both stacks

- pa / pb → push top element between stacks

- ra / rb → rotate stack (top becomes last)

- rr → rotate both stacks

- rra / rrb → reverse rotate stack (last becomes top)

- rrr → reverse rotate both stacks

## Project Rules (42)

- Written in C

- Only allowed operations are those listed above

- Must handle errors (non-numeric input, duplicates, empty args)

- Must be optimized to use as few moves as possible

- Must comply with 42 Norminette
