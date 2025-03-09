# get_next_line
## 📋 Project Overview

`get_next_line` is a project from Ecole 42 focused on implementing a function that reads and returns a single line from a file descriptor, one call at a time. This function is designed to handle reading from various inputs, including standard input (`stdin`), files, and other file descriptors. It’s crafted to handle multiple lines and to maintain memory efficiency, ensuring that only the required data is stored and managed between reads.

### The project emphasizes memory handling, buffer management, and efficient reading techniques, which are essential for working with files in C.

## 🛠️ Function Prototype

The core function you implement has the following prototype:

``` c

char *get_next_line(int fd);
```
- `fd`: The file descriptor to read from.
- Return Value: Returns the next line read from the file descriptor, including the newline character if one is encountered. If there's no more to read or if an error occurs, it returns `NULL`.

## 📁 Project Structure

1. **Core Function:**  get_next_line reads from a file descriptor line by line and manages the buffer to ensure memory efficiency.

```c

char *get_next_line(int fd);
```
2. **Helper Functions:** To handle buffer management, memory allocation, and string manipulation, helper functions are often required. Some of these might include:

- `ft_strjoin`: Joins two strings.
- `ft_strdup`: Duplicates a string up to a certain point.
- `ft_strchr`: Locates a character within a string.

Example helper function:

```c

char *ft_strjoin(char *s1, char *s2) {
    // Custom implementation of strjoin for efficient concatenation.
}
```
3. **Buffer Management:** By defining a buffer size (often `BUFFER_SIZE`), `get_next_line` uses a **static buffer** to manage reading across multiple calls and keep track of any remaining data that hasn't yet been returned.

4. **Static Variable:** The function leverages static variables to maintain data between calls, ensuring that unfinished lines and buffer overflow are handled correctly without losing data.

## 🚀 Installation and Usage
Compile the function as part of your project by linking it with the necessary helper functions.

```
gcc -Wall -Wextra -Werror get_next_line.c -o get_next_line -D BUFFER_SIZE=42
```
To use `get_next_line`:

Include `get_next_line.h` in your C file.
Link the function during compilation.
Call `get_next_line(fd)` with the desired file descriptor.

```c
#include "get_next_line.h"

int main(void) {
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

To use the stdin you can set the `fd = 0`, use this main to access it.

```c
int	main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
```

In the stdin you can only write one line, and the `\n` is taken as charachters, so you can use the next command to write new lines as you like.

```
 echo -e "hellouhwiufh\nWorld\nwue \n\t\tfgiw\n\negf" | ./get_next_line
```

output:

```
hellouhwiufh
World
wue 
                fgiw

egf
```

