#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "chromosome.h"
#include "parentselection.h"
#include "logger.h"

/* целевая функция (min: x = 1, locmin: x = 6) */
int target(int x) 
{
    int res = (int) 5 - 24 * x + 17 * pow((double)x, 2.0) - 11.0 / 3 * pow((double)x, 3.0) 
        + 1.0 / 4 * pow((double)x, 4); 
    return res;
}

int main(int argc, char **argv)
{
#define POPSIZE 100
    struct chromosome *population = (struct chromosome*)malloc(
            sizeof(struct chromosome) * POPSIZE);
    for (int i = 0; i < POPSIZE; i++) {
        population[i].id = i;
        population[i].x1 = 1;
        population[i].x2 = 2;
        population[i].x3 = 3;
        population[i].x4 = 4;
    }

    struct parents *families = panmixia(population, POPSIZE);
    int selfpar = 0;
    for (int i = 0; i < POPSIZE; i++) {
        if (families[i].one->id == families[i].two->id) 
            selfpar++;
    }
    logg(NULL, "[debug] партогинез замечен в %d случаях из %d\n", selfpar, POPSIZE); 

    return 0;
}
