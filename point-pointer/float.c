#include <stdlib.h>
#include <stdio.h>
int main() {
    printf("for loop thingy");
    int spaces = 30;
    for(int i = 0; 1; ++i) { //;; equals while loop
        printf("%i, ", i);
        if(i%spaces == 0) {
            for(int j = 0; j < spaces; j++){
                printf(" ");
            }
            if(spaces > 0 && spaces < 100) {spaces +=1;}
            if(spaces > 100) {spaces -=1;}
            printf("s:%i, ", spaces);
        }
    }
    return 0;
}