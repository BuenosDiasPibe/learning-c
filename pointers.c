#include <stdio.h>
int main()
{
    int int_point = 20;
    printf("number: %i\npointer: %p\n", int_point, &int_point);
    // <type>* name: pointer to a type
    // *name: dereference operator
    int* point = &int_point;
    printf("point: %p\ndereference: %i\n", point, *point);

    return 0;
}