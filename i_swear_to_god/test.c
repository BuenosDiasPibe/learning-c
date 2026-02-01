/*https://youtu.be/95M6V3mZgrI?si=JKyYYb3J_HhqoWJo*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct {
    char name[20];
    bool finished;
} Task;

void remove_end_line(char *name) {
    for(int i = 0; i < sizeof(name); ++i) {
        if(name[i] == '\n') {
            name[i] = '\0';
        }
    }
}

Task create_task() {
    Task t = {};
    printf("task name: ");
    fgets(t.name, sizeof(t.name), stdin);
    remove_end_line(t.name);
    return t;
}

typedef struct {
    Task* items;
    size_t count;
    size_t capacity;
} TasksList;


void da_append(TasksList *list, Task *item) {
    if(list->count >= list->capacity) {
        if(list->capacity == 0) list->capacity = 10;
        else list->capacity *=2;
        list->items = realloc(list->items, list->capacity*sizeof(*list->items));
    }
    list->items[list->count++] = *item;
}

void list_show(TasksList *list) {
    for(int j = 0; j < list->count; j++) {
        printf("\nitem %s: finished: %s\n", list->items[j].name, list->items[j].finished ? "true" : "false");
    }
}

void task_finish(TasksList *list) {
    printf("select one from 1 to %zu: ", list->count);
    char temp[5];
    int selection = atoi(fgets(temp, sizeof(temp), stdin));
    if(selection <= 0 || selection > (int)list->count) {printf("you selected nothing"); return;}

    list->items[selection-1].finished = true;
}

int main() {
    TasksList list = {0};
    for(int a = 0; a < 20; a++) {
        Task t = create_task();
        da_append(&list, &t);
    }
    task_finish(&list);
    list_show(&list);

    free(list.items);
    return 0;
}
