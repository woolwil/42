# get_next_line

*This project has been created as part of the 42 curriculum by ngvo.*

**Description**

The goal of this project is to create a function, `get_next_line`, that reads from a file descriptor and returns one line at a time.

- A "line" is defined as a sequence of characters ending with a newline (`\n`) or the end of the file (EOF).
- When called repeatedly on the same file descriptor, the function returns the next line until the entire file has been read.
- To manage data that is read but not immediately returned (e.g., when a buffer read contains multiple lines), the function uses a `static` variable to store the remainder for subsequent calls.

**Instructions**

The project includes a `Makefile` to handle compilation. The available commands are:

- `make all`: Compiles the source files and creates the necessary library/executable.
- `make clean`: Removes the intermediate object files created during compilation.
- `make fclean`: Removes all compiled files, including object files and the final program output.

**Resources**

- This project was inspired by the implementation found at: [jdecorte-be/42-Get-next-line](https://github.com/jdecorte-be/42-Get-next-line)
- Code quality and refactoring assistance provided by Gemini Code Assist.

**Algorithm Explained**

The `get_next_line` function is designed around a `static` variable to preserve data across multiple function calls. This allows the function to "remember" what has been read from the file descriptor, even after it returns a line.

The process can be broken down into three main stages:

1.  **Reading from the File (`read_file`)**
    - The function first checks if the static `buffer` already contains a newline (`\n`).
    - If not, it enters a loop that reads `BUFFER_SIZE` chunks from the file descriptor.
    - Each chunk is appended to the `static` buffer using `ft_strjoin`. This process continues until a newline is found in the buffer or the end of the file is reached.
    - This approach minimizes the number of `read` system calls by reading in larger, fixed-size chunks.

2.  **Extracting the Line (`gnl_line`)**
    - Once the buffer is guaranteed to hold at least one full line (or the rest of the file), this function is called.
    - It calculates the length of the line (up to and including the `\n`).
    - It allocates the precise amount of memory needed for this line and copies the characters from the main buffer into this new string.
    - This new string is the value returned by `get_next_line`.

3.  **Updating the Static Buffer (`gnl_next`)**
    - To prepare for the next call to `get_next_line`, the static buffer must be cleaned of the line that was just returned.
    - This function finds the start of the *next* line (the character immediately after the first `\n`).
    - It allocates new memory for this "remainder" and copies the data into it.
    - Finally, it frees the old static buffer and returns the new remainder, which is then assigned back to the static variable in `get_next_line`. If no remainder exists, it returns `NULL`, effectively resetting the state.

