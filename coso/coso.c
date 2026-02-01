#include <stdio.h>
#include <stdlib.h>
// linked_list implementation ...
int list_capacity = 0;
typedef struct TODO TODO;
struct TODO{
  int id;
  char* string;
  TODO *next;
};

void Add(TODO *n, char* todo_string)
{
  TODO *papu = n->next;
  while(papu != NULL)
  {
    papu = papu->next;
    printf(".");
  }
  (*papu).next = malloc(sizeof(TODO));
  papu->id= list_capacity++;
  papu->string = todo_string;
}

void show(TODO *n)
{
  TODO *papu = n->next;
  n->id = list_capacity++;
  printf("TODO: \n");
  while(papu != NULL)
  {
    printf("\t%i: %s", papu->id, papu->string);
    papu = papu->next;
  }
}
// ...

int main()
{
  TODO n = {0};
  for(int i = 0; i < 10; i++)
  {
    char* cosaso = malloc(sizeof(cosaso)*10);
    fgets(cosaso, 10, stdin);
    Add(&n, cosaso);
  }
  show(&n);
  return 0;
}
