// Holds functions that are of common use to other .c files

#ifndef COMMON_H_
#define COMMON_H_

// Function to run a Linux command
// Taken from Assignment 1 PDF
void Common_runCommand(char*);
// Taken from GPIO Guide
void Common_writeToFile(char*, int);
void Common_writeToFile_char(char*, char*);



#endif