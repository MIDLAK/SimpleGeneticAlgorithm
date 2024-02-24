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
/* одноточечный бинарный кроссинговер для множества семей */
struct childs* all_single_point_cross(struct parents *families, int size,
        int point_min, int point_max);

#endif /* __CROSS */
