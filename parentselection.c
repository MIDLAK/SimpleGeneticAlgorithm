#include <stdlib.h>
#include <time.h>
#include "chromosome.h"
#include "logger.h"
#include "parentselection.h"

/* панмиксия (пары выбираются случайно) */
struct parents* panmixia(struct chromosome *population, int size)
{
    /* количество пар равно количеству особей */
    struct parents *families = (struct parents*)malloc(sizeof(struct parents) * size);
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        families[i].one = &population[i];
        int r = rand() % 100; /* выбор случайно пары */
        families[i].two = &population[r];
        if (r == i) /* проверка на пару с самим собой */
            families[i].parthenogenesis = 1;
        else
            families[i].parthenogenesis = 0;
    }

    return families;
}
