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

---

## How get_next_line Works (with Diagrams)

### 1. Reading and Stashing
- Data is read from the file descriptor into a buffer.
- The buffer is appended to the stash (leftover data from previous calls).
- Example:

```
File: "Hello\nWorld\n42"
First read (BUFFER_SIZE=5):
Buffer: "Hello"
Stash:  "Hello"
Second read:
Buffer: "\nWor"
Stash:  "Hello\nWor"
Third read:
Buffer: "ld\n42"
Stash:  "Hello\nWorld\n42"
```

### 2. Extracting a Line
- The function searches for a newline (`\n`) in the stash.
- If found, it extracts everything up to and including the newline as a line to return.
- The stash is then updated to remove the returned line.
- If no newline is found, it keeps reading and appending until EOF or a newline is found.

**Diagram:**
```
Stash:  | H | e | l | l | o | \n | W | o | r | l | d | \n | 4 | 2 |
Index:    0   1   2   3   4   5   6   7   8   9  10  11  12  13
Extracted line: "Hello\n"
New stash: "World\n42"
```

### 3. Handling Multiple File Descriptors (Bonus)
- Each fd gets its own stash: `stash[fd]`.
- Example:
```
fd = 3: stash[3] = "File1..."
fd = 4: stash[4] = "File2..."
fd = 5: stash[5] = "File3..."
```
- When you call `get_next_line(fd)`, it only updates and returns lines for that fd.

---

## Explaining Edge Cases in Evaluation
- **File without trailing newline:** The last line should still be returned, even if it doesn't end with `\n`.
- **Empty file:** Should return NULL immediately.
- **Multiple fds:** Each file's state is independent; reading from one does not affect the others.
- **Memory management:** All buffers and stashes are freed when no longer needed.

---

## Tips for Explaining in Evaluation
- Walk through the process with a diagram (like above).
- Explain how you use `stash[fd]` to keep state for each file.
- Show how you handle edge cases and memory.
- Mention why you check for NULL and empty strings.
- Be ready to explain pointer arithmetic (e.g., `ft_strchr(stash, '\n') - stash`).
- Emphasize that your code is robust, portable, and memory-safe.
