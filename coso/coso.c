#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void Add(struct Node *n, int datas)
{
  struct Node *papu = n;
  printf("linea: ");
  while(papu->next != NULL)
  {
    papu = papu->next;
    print(" ");
  }
  (*papu).next = malloc(sizeof(struct Node));
  papu->data = datas;
  printf("%i\n", papu->data);
}

void show(struct Node *n)
{
  struct Node *papu = n;
  while(papu != NULL)
  {
    printf("node: %i\n", papu->data);
    papu = papu->next;
  }
  printf("null");
}
int main()
{
  struct Node n = {0};
  n.data = 1;
  int a = 1;
  while(a < 10)
  {
    Add(&n, a);
    a++;
  }

  return 0;
}
