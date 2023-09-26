#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd_file = open("testFile.txt", O_RDONLY); // read only
    printf("The file descriptor is: %d\n", fd_file);
    
    // duplicating the file descriptor for said file. 
    // dup provides the lowest available file descriptor
    int fd_file_new = dup(fd_file);
    printf("The new file descriptor is: %d\n", fd_file_new);
    
    close(fd_file);
    close(fd_file_new);
}
