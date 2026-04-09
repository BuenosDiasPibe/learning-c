#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int h;
    size_t y;
} myStruct;

int main() {
    myStruct *structs = malloc(sizeof(myStruct)*10);
    for(int i = 0; i < 10; i++) {
        structs[i] = (myStruct){i, i+2};
    }
    for(int t = 0; t < 10; t++) {
        printf("%i => %zu\n", structs[t]);
    }
}
