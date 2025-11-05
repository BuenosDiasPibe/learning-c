#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char** string;
    size_t capacity;
    size_t max_chars;
    size_t count;
} StringsList;
int init_strings(StringsList *str, size_t capacity, size_t max_chars) {
    str->capacity = capacity;
    str-> max_chars = max_chars;
    str->string = malloc(str->capacity *sizeof(char*));
    if(str->string == NULL) {
        fprintf(stderr, "memory allocation error\n");
        return 1;
    }
    for(int i = 0; i < str->capacity; i++) {
        str->string[i] = (char*)malloc((str->capacity+1)*sizeof(char));
        if(str->string[i] == NULL) {
            fprintf(stderr, "sos un boludo");
        }
        str->count++;
    }
    return 0;
}
int free_string_list(StringsList *stirngList) {
    for(int i = 0; i < stirngList->capacity; ++i) {
        free(stirngList->string[i]);
    }
    free(stirngList->string);
    return 0;
}
int main() {
    printf("WELCOME TO THE TO-DO LIST\n please add a todo: ");
    StringsList strings = {0};
    init_strings(&strings, 5, 20);
    fgets(strings.string[0], sizeof(strings.string), stdin);
    printf("TO-DO:\n\t* %s\n", *strings.string);
    printf("want to add something more? y/n: ");

    free_string_list(&strings);
    return 0;
}