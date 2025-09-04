#include "terminal.h"

#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char cwd[PATH_MAX];

int init_shell(int argc, char* argv[]) {
    if (argc < 2) return 1;

    const char* path = argv[1];
    struct stat info;

    if (stat(path, &info) != 0) {
        fprintf(stderr, "Directory does not exist or cannot be accessed.\n");
        return 1;
    } else if (S_ISDIR(info.st_mode)) {
        printf("Directory Exists!\n");

        char abs_path[PATH_MAX];
        if (realpath(path, abs_path) == NULL) {
            fprintf(stderr, "Absolute path couldnt be resolved!\n");
            return 1;
        }

        strncpy(cwd, abs_path, sizeof(cwd) - 1);
        cwd[sizeof(cwd) - 1] = '\0';
    } else {
        fprintf(stderr, "Path Exists, but its not a Directory.");
        return 1;
    }

    return 0;
}

void print_prompt() { printf("%s> ", cwd); }

char* read_line() {
    char* buffer = malloc(sizeof(char) * 1024);
    if (!buffer) {
        fprintf(stderr, "Read Buffer couldnt be allocated!\n");
        return NULL;
    }

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("you typed: %s\n", buffer);
    } else {
        fprintf(stderr, "Error or EOF reached!\n");
        return NULL;
    }

    return buffer;
}

char** parse_line(char* command) {}

int execute_command(char** tokens) { return 1; }

void destroy_shell() {}
