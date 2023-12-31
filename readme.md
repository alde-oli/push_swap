# Push_Swap Project

## Overview
The `push_swap` program is a highly efficient algorithm designed to sort numbers into a stack, using a second stack as an auxiliary data structure. This project is implemented in C, following the rigorous 42 norm.

## Features
- **Stack Visualization**: An optional feature, the `ft_print_stacks` function, allows for a visual representation of the stack states. This is especially useful for debugging or for an in-depth analysis of the sorting process. This function is not included in the final submission to adhere to project constraints, but can be added for personal use.
  ```c
  void ft_print_stacks(t_node *s_a, t_node *s_b);
  ```

- **Optimized Sorting**: The main goal of this project is to sort the numbers with the least amount of operations possible. To achieve this, a variety of algorithms have been implemented, each tailored for different scenarios and stack sizes.

## Sorting Algorithms

This project implements a series of sorting algorithms optimized for small to large data sets, ensuring high performance and adherence to the 42 Norm. The algorithms are designed to handle different cases efficiently, from sorting just a few elements to managing a larger collection of data.

### Small Data Sets

For small stacks of 3 to 5 elements, the functions `sort_three`, `sort_four`, and `sort_five` are used. These functions employ a simple yet effective strategy to sort elements using a combination of swaps (`doswap`), rotations (`dorotate`), and reverse rotations (`dorevrotate`). Each function is carefully crafted to consider all possible states of the stack to perform the minimum operations required for sorting.

- `sort_three`: Sorts three elements by considering all possible permutations and using the least number of operations.
- `sort_four`: Sorts four elements by moving the smallest element to a secondary stack and then sorting the remaining three.
- `sort_five`: Extends the logic of `sort_four` by handling an extra element, ensuring the stack is sorted with minimal moves.

### Large Data Sets

For larger data sets, the `ft_sort_radix` function implements a radix sort algorithm. This non-comparison-based sorting technique processes the elements based on their individual bits. By iterating through each binary digit of the elements, the algorithm groups numbers and progressively builds up a sorted list through multiple passes.

## Usage
Compile the program with Makefile commands and run it with a list of integers to be sorted:
```bash
make
./push_swap 1 2 3 4 5 6 7 8 9
```

The `push_swap` program outputs a series of operations that sort the stack, which can be checked using a checker program provided during evaluation.