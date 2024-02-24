#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "chromosome.h"
#include "parentselection.h"
#include "generic.h"
#include "logger.h"
#include "fitness.h"
#include "cross.h"


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
    /* новая популяция */
    struct chromosome *population = random_population(POPSIZE, XMIN, XMAX); 
    all_fitness(population, POPSIZE);

    /* отбор родителей и кроссинговер */
    struct parents *families = panmixia(population, POPSIZE);
    struct childs *childs = all_single_point_cross(&families[0], POPSIZE, 3, 3);
    for (int i = 0; i < POPSIZE; i++) {
        fitness(childs[i].one);
        fitness(childs[i].two);
    }

    int selfpar = parthenogenesis(families, POPSIZE);
    logg(NULL, "[debug] партогинез замечен в %d случаях из %d\n", selfpar, POPSIZE); 

    free(population);
    free(families);
    free(childs);
    return 0;
}
