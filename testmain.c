#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signum) 
{
    printf("\n");
}

void    signal_quit(int signum)
{
    printf("\n");
    exit(0);
}

int main() 
{
    // Install the signal handler for SIGINT (Ctrl-C)
    if (signal(SIGINT, signal_handler) == SIG_ERR)
    {
        printf("Error installing signal handler\n");
        return 1;
    }

    // Install the signal handler for SIGTSTP (Ctrl-Z)
    if (signal(SIGQUIT, signal_quit) == SIG_ERR) 
    {
        printf("Error installing signal handler\n");
        return 1;
    }

    // Wait for signals
    char buffer[1024];
    while (1) {
        write(STDOUT_FILENO, "> ", 2);  // Display prompt
        ssize_t n = read(STDIN_FILENO, buffer, sizeof(buffer));
        if (n > 0) {
            buffer[n] = '\0'; // Add null terminator to end of input string
            printf("You entered: %s", buffer); // Do something with input
        } else {
            printf("\n"); // End of input, exit program
            return 0;
        }
    }

    return 0;
}
