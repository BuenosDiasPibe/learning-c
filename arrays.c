#include <stdio.h>
#include <stdlib.h>
int main() {
    //using arrays and encripting its content (idk if this shi works)
    printf("Arrays:\n");
    char coso[] = "pucha";
    for(int i = 0; i < sizeof(coso)-1; ++i) {
        int d = coso[i];
        printf("%i\n", d);
    }
    printf("encrypting...\n");
    char enc[sizeof(coso)];
    for(int j = 0; j < sizeof(coso)-1; ++j) {
        int m = coso[j];
        int e = 13;
        m = (m^e)%26+97;
        printf("%d\n", m);
        enc[j] = m;
    }
    printf("ori: %s\nenc: %s\n", coso, enc);
    return 0;
}