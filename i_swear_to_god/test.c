/*https://youtu.be/95M6V3mZgrI?si=JKyYYb3J_HhqoWJo*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    bool finished;
    int index;
} Task;

typedef struct {
    Task* items;
    size_t count;
    size_t capacity;
} TasksList;

void list_push(TasksList *list, Task *task){
    if(list->count >= list->capacity) {
        if(list->capacity == 0) list->capacity = 200;
        else list->capacity *=2;
        list->items = realloc(list->items, list->capacity*sizeof(*list->items));
    }
    task->index = list->count;
    list->items[list->count++] = *task;
}

void list_show(TasksList *list) {
    for(int j = 0; j < list->count; j++) {
        printf("item %s ; finished: %s\n", list->items[j].name, list->items[j].finished ? "true" : "false");
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
    Task t = {.name = "fuuf", .finished = false};
    list_push(&list, &t);
    t = (Task){.name = "fuauf", .finished = false};
    list_push(&list, &t);
    task_finish(&list);
    list_show(&list);


    free(list.items);
    return 0;
}
