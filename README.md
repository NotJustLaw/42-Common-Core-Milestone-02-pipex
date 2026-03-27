Project: Pipex (The "Shell Internals" Project)

- The Mission: Replicate the shell pipe | behavior in C.

- Technical Description: Engineered a program to handle multi-process communication. Managed the execution of two commands where the output of one becomes the input of the next using pipe(), fork(), and dup2(). Focused heavily on rigorous error handling and closing file descriptors to prevent resource leaks.
