#include <stdio.h>
typedef struct {
	int x;
	int y;
} Vector2;
void moving_vector(Vector2 *vector) {
	vector->x++;
	vector->y++;
}
int main() {
	Vector2 vector = {0};
	int selected = 0;
	do {
		printf("where do you want to move?: x:");
		scanf("%i", &vector.x);
		printf("y: ");
		scanf("%i", &vector.y);
		printf("vector: {%i, %i}\n", vector.x, vector.y);
		printf("want to exit? 1: yes / 0 = no\n");
		scanf("%i", &selected);
	} while (selected != 1 && vector.x != 0 && vector.y != 0);
	return 0;
}
