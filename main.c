#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "chromosome.h"
#include "parentselection.h"
#include "generic.h"
#include "logger.h"
#include "fitness.h"



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
#define XMIN 0
#define XMAX 7
    struct chromosome *population = random_population(POPSIZE, XMIN, XMAX); 
    all_fitness(population, POPSIZE);
    struct parents *families = panmixia(population, POPSIZE);

    int selfpar = parthenogenesis(families, POPSIZE);
    logg(NULL, "[debug] партогинез замечен в %d случаях из %d\n", selfpar, POPSIZE); 

    for (int i = 0; i < POPSIZE; i++) {
        logg(NULL, "[debug] id = %d, x = %d, fitness = %d\n", 
                population[i].id, population[i].x, population[i].fitness); 
    }

    free(population);
    free(families);
    return 0;
}
