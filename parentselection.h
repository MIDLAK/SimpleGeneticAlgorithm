#ifndef __PARENTSELECTION
#define __PARENTSELECTION

#include "chromosome.h"

struct parents
{
    struct chromosome *one;
    struct chromosome *two;
    int parthenogenesis; /* признак размножения с самим собой 0 - нет, 1 - да */
};

/* панмиксия (пары выбираются случайно) */
struct parents* panmixia(struct chromosome *population, int size);

#endif /* __PARENTSELECTION */
