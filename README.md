
# GET_NEXT_LINE

This project has been created as part
of the 42 curriculum by <rodcaeta@student.42lisboa.com>

# DESCRIPTION

A project that implements a function to read content from a file descriptor, one line at a time.

# INSTRUCTIONS

Compilation

You can set any value to the BUFFER_SIZE:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

Testers

regular file:
curl -O https://raw.githubusercontent.com/rodrigobrasz/Get_Next_Line/main/miquella1.txt

empty file:
curl -O https://raw.githubusercontent.com/rodrigobrasz/Get_Next_Line/main/empty.txt

main file:
curl -O https://raw.githubusercontent.com/rodrigobrasz/Get_Next_Line/main/main.c




# ALGORITHM EXPLANATION

The primary goal is to develop a deeper understanding of static variables, dynamic memory allocation, and buffer management in C.

The function must handle multiple file descriptors simultaneously (bonus part), work with various buffer sizes, and efficiently manage memory without leaks. This project is essential preparation for future 42 projects that require file manipulation and serves as an introduction to more complex I/O operations.


# RESOURCES 

Manual

man read\
man open.2

AI Usage

I used AI to deaply understadand about BUFFERSIZE and statics variables, and to write my README since it was the first time that i wrote one.







