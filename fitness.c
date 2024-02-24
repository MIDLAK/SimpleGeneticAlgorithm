#include "chromosome.h"
#include <math.h>

/* целевая функция (min: x = 1, locmin: x = 6) */
int target(int x) 
{
    int res = (int) 5 - 24 * x + 17 * pow((double)x, 2.0) - 11.0 / 3 * pow((double)x, 3.0) 
        + 1.0 / 4 * pow((double)x, 4); 
    return res;
}

/* вычисление приспособленности особи */
void fitness(struct chromosome *ch) {
    ch->fitness = target(ch->x);
}

/* вычисление приспособленности для всех особей популяции */
void all_fitness(struct chromosome *population, int size)
{
    for (int i = 0; i < size; i++) {
        fitness(&population[i]);
    }
}
