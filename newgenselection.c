#include <stdlib.h>
#include "chromosome.h"
#include "newgenselection.h"


struct chromosome* fmax_selection(struct chromosome *population, 
        struct chromosome* childs, int size)
{
    struct chromosome* newpopulation = 
        (struct chromosome*)malloc(sizeof(struct chromosome) * size);

    int fmin = population[0].fitness;
    int imin = 0;
    int p = 0; /* imax из родителей или сыновей TODO: костыльно */
    for (int k = 0; k < size; k++) {
        fmin = 1000000000; /*TODO: страшный костыль */
        imin = 0;
        for (int i = 0; i < size * 2; i++) { 
            if (i < size) {
                if (fmin > population[i].fitness) {
                    fmin = population[i].fitness;
                    p = 1;
                    imin = i;
                }
            }

            if (fmin > childs[i].fitness) {
                fmin = childs[i].fitness;
                p = 0;
                imin = i;
            }
        }

        if (p == 1) {
            newpopulation[k].x = population[imin].x;
            newpopulation[k].fitness = population[imin].fitness;
            newpopulation[k].id = population[imin].id;

            population[imin].fitness = 1000000000; /* TODO: страшный костыль */
        }
        else {
            newpopulation[k].x = childs[imin].x;
            newpopulation[k].fitness = childs[imin].fitness;
            newpopulation[k].id = childs[imin].id;

            childs[imin].fitness = 1000000000; /*TODO: страшный костыль */
        }
    }

    return newpopulation;
}
