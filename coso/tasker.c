#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[20];
    char description[100];
    int priority;
} Task;
typedef struct {
    Task* tasks;
    size_t capacity;
    size_t count;
} Task_List;

Task addTask() {
    Task t = {0};
    printf("\n\tnombre: ");
    scanf("%s", t.name);
    printf("\tdescripcion: ");
    scanf("%s", t.description);
    printf("\tprioridad: ");
    scanf("%3i", &t.priority);
    return t;
}
void displayTask(Task *task) {
    printf("la tarea que añadiste: \n%s, %s, prioridad de %i\n", task->name, task->description, task->priority);
}
int main() {
    Task_List* tasks = malloc(sizeof(tasks));
    if(tasks == NULL) {
        fprintf(stderr, "memory not allocated\n");
        return 1;
    }
    tasks->count = 0;
    tasks->capacity = 100;
    printf("bienvenido a la consola de To-Dos, que quiere hacer:");
    print("\n\t- añadir tarea: 1\n\t- mostrar tareas: 2\n\t- salir: 3");
    int selected = 0;
    do {
        scanf("%i", selected);
        switch(selected)
        {
            case 1:
                printf("añade una nueva tarea:");
                Task task = addTask();
                break;
            case 2:
                break;
            case 3:
                printf("chauu!\n");
                break;
            default:
                printf("???");

        }
    } while (selected != 3);
    
    return 0;
}
