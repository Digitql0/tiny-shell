#include <stdio.h>

#include "terminal.h"

int main(int argc, char* argv[]) {
    printf("Program started.");

    // DEBUG
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    int exit = 0;

    char* command = NULL;
    char** tokens = NULL;

    exit = init_shell(argc, argv);

    printf("%s\n", cwd);

    while (exit != 1) {
        print_prompt();
        command = read_line();
        tokens = parse_line(command);
        exit = execute_command(tokens);
    }

    return 0;
}
