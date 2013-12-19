#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pokemon.h"

pokemon *pokemon_spawn(char *name, int awesomeness) {
	pokemon *newBorn = malloc(sizeof(pokemon));

	if (!newBorn)
		return NULL;

	newBorn->name = malloc((strlen(name)+1)*sizeof(char));
	strncpy(newBorn->name, name, strlen(name)+1);
	newBorn->awesomeness = awesomeness;

	return newBorn;
}

/* TODO: Complete this */
int pokemon_compare(void *apples, void *oranges) {
	pokemon *a1, *a2;

	a1 = (pokemon *) apples;
	a2 = (pokemon *) oranges;

	return (a1->awesomeness - a2->awesomeness);
}

void pokemon_faint(void *rip) {
    pokemon *afterlife = (pokemon *)rip;
    free(afterlife->name);
    free(afterlife);
}

int pokemon_print(void *node) {
	pokemon *a = (pokemon *)node;
	return printf("%3d, %s\n", a->awesomeness, a->name);
}

char *pokemon_getName (void *node) {
	pokemon *a = (pokemon *)node;
	return a->name;
}

int pokemon_getAwesomeness (void *node) {
	pokemon *a = (pokemon *)node;
	return a->awesomeness;
}