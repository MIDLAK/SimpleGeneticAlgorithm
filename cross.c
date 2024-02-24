#include <assert.h>
#include <stdlib.h>
#include "chromosome.h"
#include "cross.h"

/* одноточечный бинарный кроссинговер */
struct childs* single_point_cross(struct parents *family, int point)
{
    struct childs *childs = (struct childs*)malloc(sizeof(struct childs));
    childs->one = (struct chromosome*)malloc(sizeof(struct chromosome));
    childs->two = (struct chromosome*)malloc(sizeof(struct chromosome));

    if (point >= 32)
        point = 31; 
    if (point < 0)
        point = 1;

#define INT32 0xFFFFFFFF
    int mask = INT32 << point;
    int not_mask = ~ mask; /* дети получают одинаковые части битов родителей */
    childs->one->x = (family->one->x & mask) + (family->two->x & not_mask);
    childs->two->x = (family->two->x & mask) + (family->one->x & not_mask);

    return childs;
}
