#include <stdio.h>
#include "linkedList.h"
#include "animal.h"

int main() {
	List *myList;
    animal *platypus = animal_spawn("platypus", 101);
    animal *doggy    = animal_spawn("dog", 102);
    animal *shrimp   = animal_spawn("pistol shrimp", 100);
	animal *dalek    = animal_spawn("dalek", 99);
	/*animal_print(platypus);*/

	myList = LL_create(animal_compare, animal_print, animal_vaporize);

    LL_addHead(myList, doggy);
    LL_addHead(myList, platypus);
    LL_addHead(myList, shrimp);
    LL_addHead(myList, dalek);
    LL_printHead(myList);
    LL_printTail(myList);
    LL_print(myList);
    printf("%d\n", LL_length(myList));
    LL_rmTail(myList);
    LL_print(myList);
    LL_printTail(myList);
    printf("%d\n", LL_length(myList));

	return 0;
}