typedef struct animal_node {
	int awesomeness;
	char *name;
} animal;

animal *animal_spawn();

int animal_compare (void *, void *);

void animal_vaporize (void *);

int animal_print (void *);