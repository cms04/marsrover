#include "mars.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *const *argv) {
    unsigned short width = 80, height = 20, live = 0;
    char *befehle = "MMLBBBBRMM", *outputfilename = NULL, *inputfilename = NULL;
    extern char *optarg;
    char param = -1;
    while ((param = getopt(argc, argv, "h:w:b:o:i:l")) != EOF) {
        switch (param) {
            case 'h':
                height = atoi(optarg);
                break;
            case 'w':
                width = atoi(optarg);
                break;
            case 'b':
                befehle = optarg;
                break;
            case 'o':
                outputfilename = optarg;
                break;
            case 'i':
                inputfilename = optarg;
                break;
            case 'l':
                live = 1;
                break;
        }
    }
    mars_t *mars = (inputfilename == NULL) ? create_random(width, height) : create_from_file(inputfilename);
    if (mars == NULL) {
        fprintf(stderr, "ERROR: Not enough space available.\n");
        return 1;
    }
    pid_t pid = fork();
    if (pid == (pid_t) -1) {
        fprintf(stderr, "ERROR: fork() failed.\n");
        delete_mars(mars);
        return 2;
    } else if (pid == (pid_t) 0) {
        if (outputfilename != NULL) {
            save_to_file(mars, outputfilename);
        }
    } else {
        print_mars(mars);
        if (live) {
            execute_live_commands(mars);
        } else {
            execute_command_string(mars, befehle);
        }
        waitpid(pid, NULL, 0);
    }
    delete_mars(mars);
    return 0;
}
