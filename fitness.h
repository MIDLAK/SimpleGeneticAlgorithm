#ifndef __FITNESS
#define __FITNESS

#include "chromosome.h"

/* целевая функция (min: x = 1, locmin: x = 6) */
int target(int x);
/* вычисление приспособленности особи */
int fitness(struct chromosome *ch);
/* вычисление приспособленности для всех особей популяции */
void all_fitness(struct chromosome *population, int size);

#endif /* __FITNESS */
