#ifndef TERMINAL_H
#define TERMINAL_H

#include <limits.h>
#include <linux/limits.h>

extern char cwd[PATH_MAX];

int init_shell(int argc, char* argv[]);
void print_prompt();
char* read_line();
char** parse_line(char* command);
int execute_command(char** tokens);
void destroy_shell();

#endif
