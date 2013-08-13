#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animal.h"

animal *animal_spawn (char *name, int awesomeness) {
	animal *newBorn = malloc(sizeof(animal));

	if (!newBorn)
		return NULL;

	newBorn->name = malloc((strlen(name)+1)*sizeof(char));
	strncpy(newBorn->name, name, strlen(name)+1);
	newBorn->awesomeness = awesomeness;

	return newBorn;
}

int animal_compare (void *apples, void *oranges) {
	animal *a1, *a2;

	a1 = (animal *) apples;
	a2 = (animal *) oranges;

	return (a1->awesomeness - a2->awesomeness);
}

void animal_vaporize (void *rip) {
    animal *afterlife = (animal *)rip;
    free(afterlife->name);
    free(afterlife);
}

int animal_print (void *node) {
	animal *a = (animal *)node;
	return printf("%3d, %s\n", a->awesomeness, a->name);
}

char * animal_getName (void *node) {
	animal *a = (animal *)node;
	return a->name;
}

int animal_getAwesomeness (void *node) {
	animal *a = (animal *)node;
	return a->awesomeness;
}