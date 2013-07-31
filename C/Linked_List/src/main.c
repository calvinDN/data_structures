#include <stdio.h>
#include "linkedList.h"
#include "animal.h"

int main() {
	List *myList;
	//animal *platypus = animal_spawn("platypus", 100);
	//animal_print(platypus);

	myList = LL_create(animal_compare, animal_print, animal_vaporize);

    

	return 0;
}