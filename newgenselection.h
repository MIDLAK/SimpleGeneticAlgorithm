#ifndef __GENSELECTION
#define __GENSELECTION

#include "chromosome.h"

/* простой отбор N лучших */
struct chromosome* fmax_selection(struct chromosome *population, 
        struct chromosome* childs, int size);

#endif /* __GENSELECTION */
