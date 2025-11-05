#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

void show_folk(Person *pPerson) {
    printf("folk: %i\n\tname %s\n\tage: %i\n", pPerson->id, pPerson->name, pPerson->age);
}

int main() {
    int increment = 0;
    Person persons[10];
    printf("create folks: \n");
    int n = sizeof(persons)/sizeof(persons[0]);

    while(increment<n) {
        Person folk = {.id = increment};
        printf("folk number %i\n", increment);
        printf("name: "); fgets(folk.name, sizeof(folk.name), stdin);
        char age[4];
        printf("age: "); fgets(age, sizeof(age), stdin);
        folk.age = atoi(age);
        persons[increment] = folk;

        increment++;

        printf("continue adding folks?\n");
        char want[3]; fgets(want, sizeof(want), stdin);
        printf("want: %s\n", want);

        while(strcmp("no", want) == 0 && increment<n) {
            Person f = {.id = increment};
            persons[increment] = f;
            increment++;
        }
    }
    printf("ok... showing folks\n");
    for(int i = 0; i < n; ++i) {
        show_folk(&persons[i]);
    }
    return 0;
}
