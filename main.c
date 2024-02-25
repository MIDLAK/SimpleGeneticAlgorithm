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
#include "mutation.h"
#include "newgenselection.h"


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

/* <<распаковка>> структуры childs в структуру chromosome */
struct chromosome* childs_to_population(struct childs* childs, int size)
{
#define CHROMOSOME_IN_ONE_CHILDS 2 /* у каждой пары по два ребёнка */
    struct chromosome *population = 
        (struct chromosome*)malloc(sizeof(struct chromosome) * size * CHROMOSOME_IN_ONE_CHILDS);

    int pop_counter = 0;
    for (int i = 0; i < size; i++) {
        population[pop_counter] = *childs[i].one;
        population[pop_counter+1] = *childs[i].two;

        pop_counter += 2;
    }

    return population;
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
    struct childs *childs = all_single_point_cross(&families[0], POPSIZE, 1, 3);

    /* мутация и вычисление приспособленности */
#define MAX_MUTATION_BIT 10 
#define MUTATION_PROBABYLITY 0.15 /*TODO: Генерация случайных чисел какая-то странная */
    for (int i = 0; i < POPSIZE; i++) {
        mutation(childs[i].one, MAX_MUTATION_BIT, MUTATION_PROBABYLITY); 
        mutation(childs[i].two, MAX_MUTATION_BIT, MUTATION_PROBABYLITY); 
        fitness(childs[i].one);
        fitness(childs[i].two);

        /*
        logg(NULL, "[debug] ch1 = [x = %d; fit = %d]  ch2 = [x = %d; fit = %d]\n",
                childs[i].one->x, childs[i].one->fitness, 
                childs[i].two->x, childs[i].two->fitness); 
        */
    }

    struct chromosome *childs_population = childs_to_population(childs, POPSIZE);

    /*
    for (int i = 0; i < POPSIZE * 2; i++) {
        logg(NULL, "[debug] i = %d, x = %d, f = %d\n", 
                i, childs_population[i].x, 
                childs_population[i].fitness); 
    }
    */

    struct chromosome *newgen = fmax_selection(population, childs_population, POPSIZE);

    int fmin = 10000000;
    int imin = 0;
    for (int i = 0; i < POPSIZE; i++) {
        if(newgen[i].fitness < fmin) {
            imin = i;
            fmin = newgen[i].fitness;
        }

        logg(NULL, "[debug] i = %d, x = %d, f = %d\n", 
                i, newgen[i].x, 
                newgen[i].fitness); 
    }
    logg(NULL, "[debug] newpop i = %d, x = %d, f = %d\n", 
            imin, newgen[imin].x, 
            newgen[imin].fitness); 

   

    int selfpar = parthenogenesis(families, POPSIZE);
    logg(NULL, "[debug] партогинез замечен в %d случаях из %d\n", selfpar, POPSIZE); 

    free(population);
    free(families);
    free(childs);
    free(childs_population);
    return 0;
}
