#ifndef __CROSS
#define __CROSS

#include "chromosome.h"
#include "parentselection.h"

struct childs {
    struct chromosome* one;
    struct chromosome* two;
};

/* одноточечный бинарный кроссинговер */
struct childs* single_point_cross(struct parents *family, int point);

#endif /* __CROSS */
