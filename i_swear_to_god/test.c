#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char *name;
    bool finished;
} Task;

typedef struct {
    size_t capacity;
    size_t count;
    Task* tasks;
} TasksList;

TasksList init_tasksList() {
    //__asm__("int3");
    TasksList task = {0};
    task.capacity = 200;
    task.tasks = malloc(sizeof(Task)*task.capacity);
    return task;
}
void addTask(TasksList *list, Task *task) {
    //__asm__("int3");
    list->count+=1;
    if(list->capacity < list->count) {
        list->capacity *= 2;
        list->tasks = (Task *) realloc(list->tasks, list->capacity*sizeof(*list->tasks));
    }
    list->tasks[list->count] = *task;
}

Task createTask(char f) {
    //__asm__("int3");
    printf("name: ");
    Task task = {.finished = false};

    char io[6] = "fuck";
    io[5] = f;
    //fgets(io, sizeof(io), stdin);
    task.name = io;
    printf("%s", task.name);

    return task;
}

void show_tasks(TasksList *list) {
    __asm__("int3");
    size_t count = list->count;
    if(count == 0) return;
    char *namea = list->tasks[0].name;
    printf("name: %s", namea);
    for(size_t i = 0; i < count; i++) {
        char *name = list->tasks[i].name;
        char finished = list->tasks[i].finished;
        printf("name: %s, finished: %i", name, finished);
    }
}
void finish_task(TasksList *list) { }

bool selection(TasksList *list, int s) {
    printf("select an option:\n\t1. create task\n\t2. show all taks\n\t3. finish a task\n: ");
    //char tmp[5];
    //int select = atoi(fgets(tmp, sizeof(tmp), stdin));
    int select = s;
    switch(select) {
        case 0:
            return false;
            break;
        case 1:
            Task temp = createTask('f');
            addTask(list, &temp);
            break;
        case 2:
            show_tasks(list);
            break;
        case 3:
            finish_task(list);
        default:
            printf("not an option");
            break;
    }
    return true;
}

int main() {
    TasksList list = init_tasksList();
    bool is_running = true;
    int s = 1;
    int u = 0;
    while(is_running) {
        is_running = selection(&list, s);
        if(u > 5) {
            s++;
        }
        u++;
    }
    free(list.tasks);
    return 0;
}
