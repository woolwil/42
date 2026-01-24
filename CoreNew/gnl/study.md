# get_next_line Study Guide

## Key Concepts
- **File Descriptor (fd):** Integer representing an open file.
- **Static Variable:** Used to keep state between function calls.
- **Stash:** Buffer holding leftover data between reads.
- **Buffer Size:** Set at compile time, controls read chunk size.

## Mandatory Implementation
- Use a static stash to store data between calls.
- Read from fd into buffer, append to stash, extract lines.
- Handle edge cases: empty files, files with/without trailing newlines.
- Free memory properly.

## Bonus Implementation
- Use a static array (e.g., `stash[OPEN_MAX]`) to support multiple fds.
- Each fd gets its own stash: `stash[fd]`.
- Check that `fd` is within bounds before using as index.
- Clean up stash when done.

## Common Pitfalls
- Returning empty lines at EOF (should return NULL).
- Not freeing memory (memory leaks).
- Not handling files without trailing newlines.
- Using variable-length arrays for static storage (not allowed).

## Testing
- Test with files ending and not ending with newlines.
- Test with multiple files and file descriptors.
- Test with different BUFFER_SIZE values.

## Useful Resources
- [POSIX open()](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html)
- [C Pointer Arithmetic](https://en.cppreference.com/w/c/language/pointer)
- [Limits.h Reference](https://en.cppreference.com/w/c/header/limits.h)

## Tips
- Use `ft_strchr` to find newlines efficiently.
- Use pointer arithmetic to get indices.
- Always check for NULL and empty strings before processing.
- Document your code and logic for easier debugging.
