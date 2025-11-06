typedef struct {
	bool is_alive;
	int age;
	char *name;
	uint64_t stupidness;
} Human;
typedef struct {
	bool is_alive;
	int age;
	char *name;
	Human owner;
} Dog;
