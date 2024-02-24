#include "generic.h"
#include "chromosome.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

/* генерация случайной популяции */
struct chromosome* random_population(int size)
{
    struct chromosome *population = (struct chromosome*)malloc(
            sizeof(struct chromosome) * size);

    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        population[i].id = i;
        population[i].x = rand() % 40;
        population[i].fitness = 0;
    }

    return population;
}
