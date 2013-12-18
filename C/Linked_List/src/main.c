#include <stdio.h>
#include "pokemon.h"
#include "linkedList.h"

#define LIST_SIZE 10

int main() {
    List *L;
    pokemon *squirtle, *charmander, *bulbasaur;

    squirtle = pokemon_spawn("squirtle", 30);
    charmander = pokemon_spawn("charmander", 20);
    bulbasaur = pokemon_spawn("bulbasaur", 40);
    L = LL_create(pokemon_compare, pokemon_print, pokemon_faint);

    LL_addHead(L, bulbasaur);
    LL_addTail(L, squirtle);
    LL_addTail(L, charmander);
    LL_rmTail(L);
    printf("-\n");
    LL_debug(L);
    LL_destroy(L);
    return 0;
}