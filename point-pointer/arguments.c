#include <stdio.h>
int main(int argsc, char *argsv[]) {
    printf("arguments passed: %i\n", argsc);
    for(int i = 1; i < argsc; ++i) {
        printf("arg %i: %s\n", i, argsv[i]);
    }
    return 0;
}