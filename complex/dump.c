/*
    A simple disassembler
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "opcodes.h"
#include "vm.h"

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("error: no input files\n");
        return -1;
    }

    // filename
    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("error[1]: could not read file `%s`\n", filename);
        return -1;
    }

    // read the "binary" file
    char buff[16];
    bool flag = false;
    int ret; 

    ret = fscanf(file, "%s", buff);
    if(ret) {
        if (strcmp(buff, SIGNATURES) == 0) {
            printf("%s", buff);
        } else {
            printf("error: not zzlang bytecode `%s`\n", filename);
            return -1;
        }
    } else {
        printf("error[2]: could not read file `%s`\n", filename);
        return -1;
    }

    while (fscanf(file, "%s", buff) > 0) {
        if (strcmp(buff, ":") == 0) {
              flag = true;
              printf("\n%s ", buff);
              continue;
        }
        if (flag) {
            flag = false;
            int index = atoi((const char *)buff);
            printf("%-3s ", symbols[index]);
        } else {
            printf("%s ", buff);
        }
    }
    printf("\n");
    
    // close the file
    fclose(file);

    return 0;
}
