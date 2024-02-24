#ifndef __MUTATION
#define __MUTATION

#include "chromosome.h"

/* случайное инвертирование одного гена */
void mutation(struct chromosome *ch, int bitmax, float probability);
/* мутация всей популяции */
void all_mutation(struct chromosome *population, int size, int bitmax, float probability);

#endif /* __MUTATUION */
