#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // printf("%s\n", argv[0]);

    // takes path of executable binary file
    // any number of arguments can be passed, but the last one must be NULL
    // put your own path here onwards
    execl("/bin/ls", "/bin/ls", "-lh", "/Users/ashmitkx/Documents/code/os/", NULL);

    // however, the os already loads files under /bin/ into the PATH variable
    // so we can just use the name of the binary file
    // execlp("ls", "ls", "-lh", "/Users/ashmitkx/Documents/code/os/", NULL);

    // instead of having separate arguments, we can pass them as an array
    // notice that we use the full path here
    // char* args1[] = {"/bin/ls", "-lh", "/Users/ashmitkx/Documents/code/os/", NULL};  
    // execv("/bin/ls", args1);

    // now lets take advantage of the PATH variable
    // char* args2[] = {"ls", "-lh", "/Users/ashmitkx/Documents/code/os/", NULL};
    // execvp("ls", args2);
    
    // what does exec return?
    // exec kills the current process and replaces it with the new one
    // int ret = execlp("ls", "ls", "-lh", "/Users/ashmitkx/Documents/code/os/", NULL);
    
    // only if exec fails does it return -1
    // failing means that the new process could not be created
    // if the process was created, but the ls command threw an error, we do not consider that a failure on exec's part
    // printf("Return value: %d\n", ret);
    
    // but what if I actually have some peice of code to run after exec?
    // if (!fork()) // child will execute and die
    //     execlp("ls", "ls", "-lh", "/Users/ashmitkx/Documents/code/os/", NULL);
    // wait(NULL); // wait for child to die, else bad things happen
    // printf("More code ...\n"); // parent can continue execution

    /* 
        You can skip the next 2 functions if you want
     */

    // now lets pass our own environment variables
    // char* const env[] = {"HOSTNAME=github.com", "PORT=22", NULL}; // NULL is required
    // execle("/bin/bash", "/bin/bash", "-c", "echo \"$HOSTNAME:$PORT\"", NULL, env);

    // we can use an array of arguments instead
    // char* const env[] = {"HOSTNAME=github.com", "PORT=22", NULL}; // NULL is required
    // char* args3[] = {"bash", "-c", "echo \"$HOSTNAME:$PORT\"", NULL};
    // execvpe("bash", args3, env);

    return 0;
}
