*This project has been created as part of the 42 curriculum by ngvo.*

# Description
This project implements the `get_next_line` function, which reads a line from a file descriptor efficiently and safely. The goal is to handle reading from files, including edge cases, and to support multiple file descriptors in the bonus part.

# Instructions
- Compile with: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=<value> get_next_line.c get_next_line_utils.c <main.c>`
- For bonus: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=<value> get_next_line_bonus.c get_next_line_utils_bonus.c <main.c>`
- Run the executable to test reading lines from files.
- Make sure to provide a valid file as input.

# Resources
- **get_next_line** subject pdf
- [POSIX Documentation](https://pubs.opengroup.org/onlinepubs/9699919799/)
	- Provides official information about system calls and standards (like open, read, file descriptors, limits, etc.)
- [C Library Reference](https://en.cppreference.com/w/c)
	- Offers details about standard C functions (like malloc, free, string functions, etc.).
- **[AI Usage]**: No AI-generated code was used in the implementation, but AI was used for code review and study guidance.
- [Tripouille gnlTester](https://github.com/Tripouille/gnlTester)

# Algorithm Explanation
The algorithm uses a static stash to store leftover data between calls. It reads from the file descriptor into a buffer, appends to the stash, and extracts lines one at a time. For the bonus, an array indexed by file descriptor is used to manage multiple files simultaneously. Memory is managed carefully to avoid leaks and handle edge cases.

# Additional Sections
- Usage examples and feature list can be added as needed.
- Technical choices: C, POSIX, static memory management.
