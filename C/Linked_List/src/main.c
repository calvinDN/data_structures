#include <stdio.h>
#include "pokemon.h"
#include "list.h"

#define LIST_SIZE 10

int main() {
    struct listNode *L;
    pokemon *squirtle, *charmander, *bulbasaur;

    squirtle = pokemon_spawn("squirtle", 30);
    charmander = pokemon_spawn("charmander", 20);
    bulbasaur = pokemon_spawn("bulbasaur", 40);
    L = list_create();
    list_addHead(L, squirtle);
    list_addHead(L, charmander);
    list_addHead(L, bulbasaur);
    list_print(L, pokemon_print);
    return 0;
}