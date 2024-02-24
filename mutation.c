#include <time.h>
#include <stdlib.h>
#include "mutation.h"

/* случайное инвертирование одного гена */
void mutation(struct chromosome *ch, int bitmax)
{
    srand(time(NULL)); 
    int shift = rand() % bitmax;
    int mask = 1 << shift;
    ch->x ^= mask;
}

/* мутация всей популяции */
void all_mutation(struct chromosome *population, int size, int bitmax)
{
    for (int i = 0; i < size; i++) {
        mutation(&population[i], bitmax);
    }
}

