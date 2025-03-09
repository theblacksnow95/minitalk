# ft_printf - 42 School Project
### 📋 Project Overview
The ft_printf project is a foundational assignment at Ecole 42, aimed at developing a custom implementation of the standard C library function printf. The primary goal is to deeply understand variadic functions, formatted output, and low-level input/output handling.

## 🎯 Objectives
The main objectives of `ft_printf` include:

1. **Replicating printf:** Implement a function that mimics the behavior of the original printf function.
2. **Handling Multiple Conversions:** Support various format specifiers like `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, and `%X`.
3. **Managing Edge Cases:** Address all possible edge cases such as null pointers, integer limits, and invalid format specifiers.
4. **Error Management:** Ensure correct error returns, especially on write failures.
5. **Learning Modular Code:** Develop skills in modular coding and project organization.
## 🗂️ Project Structure
The `ft_printf` project is organized into the following files and functions:

### Core Files

- **ft_printf.c:** Contains the main `ft_printf` function that processes format strings, initializes variables, and manages the output. It iterates through the format string, detecting format specifiers and calling helper functions as needed.

### Helper Files:

- **ft_checkflags.c:** Handles format specifiers and selects the appropriate helper function for each type (e.g., `ft_putstr`, `ft_putnbr`).
  
- **ft_putnbr.c:** Contains functions to handle integer outputs (e.g., `%d`, `%i`, `%u`).
  
- **ft_putstr.c:** Manages string output (`%s`) and character printing (`%c`).
  
- **ft_putpointer.c:** Prints memory addresses for pointers (`%p`).

- **ft_putnbrhex.c:** Converts integers to hexadecimal strings (`%x`, `%X`).
### Utility Functions

- `ft_putchar_int`: Writes a single character to fd and returns 1 (or -1 on error).

- `ft_putstr_fd_int`: Writes a string to fd, managing write errors and returning the number of characters printed.
- `ft_putnbr_fd`: Handles integer conversions and outputs, recursively processing each digit.

### Header File
- `ft_printf.h`: Declares all project functions, macros, and includes necessary libraries, ensuring consistent functionality across files.

### ⚙️ Usage
To test `ft_printf`, clone this repository, compile using make, and then call `ft_printf` as you would use printf in C. Example:

``` c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! Your score is %d.\n", "world", 100);
    return 0;
}
```
