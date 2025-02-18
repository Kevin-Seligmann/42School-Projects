# get_next_line

A C function to read files, line by line.

## Requirements

Styleguide [Norminette](https://github.com/42School/norminette)

- Repeated calls read the file descriptor pointed by fd, one line at the time.
- If EOF is reached or there's an error, returns NULL.
- It must be able to read from STDIN
- A macro BUFFER_SIZE must be defined, read() will read on blocks of that size.
- Must compile with flags -Wall -Wextra -Werror, have no leaks, or unexpected exits.
- Only read, malloc and free external functions are allowed
- Only one static variable is used
- It should be able to read from multiples files
