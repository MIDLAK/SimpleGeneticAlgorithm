#include "generic.h"
#include "chromosome.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

/* генерация случайной популяции */
struct chromosome* random_population(int size, int xmin, int xmax)
{
    struct chromosome *population = (struct chromosome*)malloc(
            sizeof(struct chromosome) * size);

    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        population[i].id = i;
        population[i].x = rand() % (xmax + 1 - xmin) + xmin;
        population[i].fitness = 0;
    }

    return population;
}
