#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    printf("what's your name?: ");
    char name[10];
    fgets(name, 10, stdin);
    name[strlen(name)-1] = *"\0";
    printf("hello %s, what's your age? ", name);

    fgets(name, 10, stdin);
    int age = atoi(name);
    if(age < 0 && age > 100) {
        printf("nah ur lying");
        return 1;
    }
    printf("cool, your age is %i", age);
    return 0;
}
