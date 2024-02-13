/**
 * Assignment 2: Simple UNIX Shell
 * @file pcbtable.h
 * @author JOHN BARBONIO
 * @brief This is the main function of a simple UNIX Shell. You may add
 * additional functions in this file for your implementation
 * @version 0.1
 */
 // You must complete the all parts marked as "TODO". Delete "TODO" after you are
 // done. Remember to add sufficient and clear comments to your code

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

#define MAX_LINE 80 // The maximum length command

/**
 * @brief parse out the command and arguments from the input command separated
 * by spaces
 *
 * @param command
 * @param args
 * @return int
 */
int parse_command(char command[], char* args[]) {
    int index = 0;
    // first case exception to enter strtok
    char* parser = strtok(command, " \n");
    args[index] = parser;

    while (parser != NULL) {
        // cout << "[" << args[index] << "]" << endl;
        index++;
        parser = strtok(NULL, " \n");
        args[index] = parser;
    }
    args[index + 1] = NULL; // null to terminate command
    return index;
}

// TODO: Add additional functions if you need
/**
 * @brief The main function of a simple UNIX Shell. You may add additional
 * functions in this file for your implementation
 * @param argc The number of arguments
 * @param argv The array of arguments
 * @return The exit status of the program
 */
int main(int argc, char* argv[]) {
    char command[MAX_LINE];       // the command that was entered
    char* args[MAX_LINE / 2 + 1]; // parsed out command line arguments
    int should_run = 1;           /* flag to determine when to exit program */
    char* historybuffer[10][MAX_LINE];
    int hbufsize = 0;
    // TODO: Add additional variables for the implementation.

    while (should_run) {
        printf("osh>");
        fflush(stdout);
        // Read the input command
        char* copiedcmd = fgets(command, MAX_LINE, stdin);

        // avoid copying !! cmd itself to history
        if (strcmp(copiedcmd, "!!") != 0)
            historybuffer[hbufsize][0] = copiedcmd;
        cout << copiedcmd << endl;
        // Parse the input command
        int num_args = parse_command(command, args);

        // TODO: Add your code for the implementation
        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) parent will invoke wait() unless command included &
         */
        int rc = fork();

        // exit function
        if (strcmp(command, "exit") == 0) {
            exit(1);
        }
        // catch history cmd
        if (strcmp(command, "!!") == 0)
        {
            // get the cmd from the history buffer (couldn't figure out )
            char* parser = strtok(historybuffer[hbufsize][0], " \n");
            num_args = parse_command(parser, historybuffer[hbufsize]);
        }

        if (rc < 0) {
            // fork failed, exit
            // fprintf(stderr, "fork failed\n");
            // exit(0);
        }
        else if (rc == 0) {
            // printf("I am in child process\n");
            int status = execvp(args[0], args);
            if (status == -1)
            {
                printf("Command not found");
            }
            exit(1);
        }
        else {
            // printf("now in parent\n");
            wait(NULL);
        }
    }
    return 0;
}