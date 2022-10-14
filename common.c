#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct timespec time1, time2 = {0.3, 0};


void Common_runCommand(char *command)
{
    // Execute the shell command (output into pipe)
    FILE *pipe = popen(command, "r");
    // Ignore output of the command; but consume it
    // so we don't get an error when closing the pipe.
    char buffer[1024];
    while (!feof(pipe) && !ferror(pipe))
    {
        if (fgets(buffer, sizeof(buffer), pipe) == NULL)
            break;
        // printf("--> %s", buffer); // Uncomment for debugging
    }
    // Get the exit code from the pipe; non-zero is an error:
    int exitCode = WEXITSTATUS(pclose(pipe));
    if (exitCode != 0)
    {
        perror("Unable to execute command:");
        printf(" command: %s\n", command);
        printf(" exit code: %d\n", exitCode);
    }
}

void Common_writeToFile(char *filename, int number)
{
   
    // Use fopen() to open the file for write access.
    FILE *pFile = fopen(filename, "w");
    if (pFile == NULL) {
    printf("ERROR: Unable to open export file.\n");
    exit(1);
    }
    // Write to data to the file using fprintf():
    fprintf(pFile, "%d", number);
    
    // Close the file using fclose():
    fclose(pFile);

    nanosleep(&time1, &time2);

}

void Common_writeToFile_char(char *filename, char *word)
{
   
    // Use fopen() to open the file for write access.
    FILE *pFile = fopen(filename, "w");
    if (pFile == NULL) {
    printf("ERROR: Unable to open export file.\n");
    exit(1);
    }
    // Write to data to the file using fprintf():
    fprintf(pFile, "%s", word);
    // Close the file using fclose():
    fclose(pFile);

    nanosleep(&time1, &time2);

}