#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int fd_file = open("testFile.txt", O_RDWR); // read and write
    printf("The file descriptor is: %d\n", fd_file);
    
    // STDIN - 0 - STDIN_FILENO
    // STDOUT - 1 - STDOUT_FILENO
    // STDERR - 2 - STDERR_FILENO
    
    // duplicating the file descriptor for to STDOUT
    int std_out = dup(1);
    int fd1 = dup2(fd_file, 1);
    
    // ls writes to file descritor 1, and since 1 is now testFile.txt
    // ls will be written into testFile.txt
    execlp("ls", "ls", "/Users/ashmitkx/Documents/code/os/", NULL);
    
    close(fd1);
    close(fd_file);
    
    // // restore stdout
    // dup2(std_out, 1);
    
    // fd_file = open("testFile.txt", O_RDONLY);
    // printf("The file descriptor is: %d\n", fd_file);
    
    // // duplicating the file descriptor for to STDIN
    // int fd0 = dup2(fd_file, 0);
    
    // // wc reads from file descritor 0, and since 0 is now testFile.txt
    // // wc will read from testFile.txt
    // execlp("wc", "wc", "-l", NULL);
    
    // close(fd0);
    // close(fd_file);
}
