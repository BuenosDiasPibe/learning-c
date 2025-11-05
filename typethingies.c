#include <stdio.h>

int mango() {
    long int coso = 0xfffffffffffffff;
    if(coso <0) return 1;
    __uint8_t plato = 18;
    printf("coso: %li, plato: %i, sizeof(coso): %zu\n", coso, plato, sizeof(coso));
    return 0;
}

int main() {
    printf("error?: %i\n", mango());
}
