#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "chromosome.h"
#include "parentselection.h"
#include "generic.h"
#include "logger.h"


/* целевая функция (min: x = 1, locmin: x = 6) */
int target(int x) 
{
    int res = (int) 5 - 24 * x + 17 * pow((double)x, 2.0) - 11.0 / 3 * pow((double)x, 3.0) 
        + 1.0 / 4 * pow((double)x, 4); 
    return res;
}

/* подсчёт пар, образованных с самим собой */
int parthenogenesis(struct parents *families, int size)
{
    int selfpar = 0;
    for (int i = 0; i < size; i++) {
        if (families[i].one->id == families[i].two->id) 
            selfpar++;
    }

    return selfpar;
}

int main(int argc, char **argv)
{
#define POPSIZE 100
    struct chromosome *population = random_population(POPSIZE); 
    struct parents *families = panmixia(population, POPSIZE);

    int selfpar = parthenogenesis(families, POPSIZE);
    logg(NULL, "[debug] партогинез замечен в %d случаях из %d\n", selfpar, POPSIZE); 

    free(population);
    free(families);
    return 0;
}
