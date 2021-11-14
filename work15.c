#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line) {
    char ** args = malloc(5*sizeof(char *));
    char *curr = line;
    char *e;
    int i = 0;
    while((e = strsep(&curr," "))) {
        args[i] = e;
        i++;
    }
    return args;
}

int main () {
    printf("Input:"); 
    char line[100];
    fgets(line, 100, stdin); // ls -a -l
    line[strcspn(line, "\n")] = 0;
    char ** args = parse_args(line);
    execvp(args[0], args);
    return 0;
}