Sure! Here's a sample README for your `push_swap` project. This README will include sections that describe the project, how to compile and run it, and some examples.

---

# Push Swap

Welcome to the `push_swap` project! This project is a sorting algorithm challenge that involves sorting data on a stack using a limited set of operations. The goal is to sort the data using the fewest number of operations possible.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction
The `push_swap` project is a sorting algorithm implemented in C. The challenge is to take a list of integers and sort them using a stack-based approach with a specific set of operations. The operations allowed are:
- `sa` (swap a): Swap the first two elements at the top of stack a.
- `sb` (swap b): Swap the first two elements at the top of stack b.
- `ss` (swap a and b): `sa` and `sb` at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a.
- `pb` (push b): Take the first element at the top of a and put it at the top of b.
- `ra` (rotate a): Shift all elements of stack a up by one.
- `rb` (rotate b): Shift all elements of stack b up by one.
- `rr` (rotate a and b): `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shift all elements of stack a down by one.
- `rrb` (reverse rotate b): Shift all elements of stack b down by one.
- `rrr` (reverse rotate a and b): `rra` and `rrb` at the same time.

## Features
- Efficient sorting algorithm with minimal operations.
- Handles various edge cases and different input sizes.
- Written in C for performance and low-level control.

## Installation
To compile and run the `push_swap` project, you will need to have `gcc` and `make` installed on your system.

1. Clone the repository:
    ```
    git clone https://github.com/BusCops/push_swap.git
    cd push_swap
    ```

2. Compile the project:
    ```
    make
    ```

This will generate the `push_swap` and `checker` executables.

## Usage
To use the `push_swap` executable, provide a list of integers as arguments. This will output the sequence of operations needed to sort the list.

Example:
```
./push_swap 4 3 2 1
```

To verify that the operations correctly sort the list, you can use the `checker` executable:
```
ARG="4 3 2 1"; ./push_swap $ARG | ./checker $ARG
```

If the list is sorted, `checker` will output `OK`. Otherwise, it will output `KO`.

## Examples
Here are a few examples of how to use the `push_swap` and `checker` programs:

Example 1:
```
./push_swap 5 2 8 3 1
```

Example 2:
```
ARG=$(shuf -i 1-100 -n 10); ./push_swap $ARG | ./checker $ARG
```

## Contributing
Contributions are welcome! If you have any suggestions or improvements, please submit a pull request or open an issue.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Feel free to adjust the content to better fit your project's specifics and personal preferences.
