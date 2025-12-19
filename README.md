
# GET_NEXT_LINE

*This project has been created as part
of the 42 curriculum by <rodcaeta@student.42lisboa.com>*

# DESCRIPTION

The primary goal is to develop a deeper understanding of static variables, dynamic memory allocation, and buffer management in C.

The function must handle multiple file descriptors simultaneously (bonus part), work with various buffer sizes, and efficiently manage memory without leaks. This project is essential preparation for future 42 projects that require file manipulation and serves as an introduction to more complex I/O operations.

# INSTRUCTIONS

Compilation

You can set any value to the BUFFER_SIZE:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=* get_next_line.c get_next_line_utils.c main.c -o gnl

valgrind ./gnl

Testers

regular file:
curl -O https://raw.githubusercontent.com/rodrigobrasz/Get_Next_Line/main/miquella1.txt

empty file:
curl -O https://raw.githubusercontent.com/rodrigobrasz/Get_Next_Line/main/empty.txt

main file:
curl -O https://raw.githubusercontent.com/rodrigobrasz/Get_Next_Line/main/main.c




# ALGORITHM EXPLANATION

The get_next_line function is designed to read a file descriptor and return one line at a time, preserving the last function call, until reaches the end of the file.

To reach that behavior we must use static variables, dynamic memory allocation and buffer management.

1. Statics variables\
A static variable is used to store leftover data that was read from the file descriptor but not yet returned as a full line.\
-This allows the function to remember his previous reads\
-The stored data persists between function calls.\
-In the bonus version, a separate static storage is maintained for each file descriptor

2. Reading from the File Descriptor\
  The function reads data using the read() system call:
Data is read in chunks of size BUFFER_SIZE
Each read is appended to the static buffer
Reading continues until:\
-A newline character (\n) is found\
-Or read() returns 0 (end of file)\
-Or read() returns -1 (error)

3. Memory Management\
Throughout the algorithm:\
-All memory is allocated dynamically using malloc\
-Allocated memory is properly freed to avoid memory leaks\
-No unnecessary memory copies are performed

4. Bonus: Multiple File Descriptors\
In the bonus part:\
-The algorithm uses an array (or similar structure) of static pointers\
-Each file descriptor has its own independent buffer\
-This allows reading from multiple file descriptors alternately without data loss or conflicts


# RESOURCES 

Manual

man read\
man open.2

AI Usage

I used AI to deaply understadand about BUFFERSIZE and statics variables, and to write my README since it was the first time that i wrote one.

