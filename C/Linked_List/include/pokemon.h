typedef struct pokemon_node {
	int awesomeness;
	char* name;
} pokemon;

pokemon* pokemon_spawn();

int pokemon_compare(void *, void *);

void pokemon_faint(void *);

int pokemon_print(void *);