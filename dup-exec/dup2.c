// credit: https://github.com/wags-1314/csf372-os-examples/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd_file = open("testFile.txt", O_RDWR); // read and write
    printf("First fopen file descriptor is: %d\n", fd_file);
    
    // STDIN - 0 - STDIN_FILENO
    // STDOUT - 1 - STDOUT_FILENO
    // STDERR - 2 - STDERR_FILENO
    
    // duplicating the file descriptor for it to a specific fd
    int std_out = dup(1);
    int fd1 = dup2(fd_file, 1);

    // printf writes to file descritor 1, and since 1 is now testFile.txt
    // printfs will be written into testFile.txt
    printf("This is a redirected printf.c\n");
    
    close(fd_file);
    close(fd1);
    
    // // restore stdout
    // dup2(std_out, 1);

    // fd_file = open("testFile.txt", O_RDONLY);
    // printf("Second fopen file descriptor is: %d\n", fd_file);

    // // duplicating the file descriptor for to STDIN
    // int fd0 = dup2(fd_file, 0);
    // char str[100];
    
    // // scanf reads from file descritor 0, and since 0 is now testFile.txt
    // // scanfs will read from testFile.txt
    // scanf("%s", str);
    // printf("The string is: %s\n", str);
    
    // close(fd_file);
    // close(fd0);
}
