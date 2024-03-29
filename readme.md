# О программе

Представлена простая реализация генетического алгоритма для целевой функции: $$f(x) = 5 - 24x + 17x^2 - \frac{11}{3}x^3 + \frac{1}{4}x^4.$$

## Оговорка
Поскольку задачей было попробовать реализовать некоторые генетические операторы, то не было смысла создавать много поколений (нет цикла в ```main```).

## Настроки
В ```main``` через ```#define``` определны следующие константы:

    - POPSIZE <размер генерируемой популяции>;
    - XMIN <нижняя граница генерируемых чисел>;
    - XMAX <верхняя граница генерируемых чисел>;
    - MAX_MUTATION_BIN <максимальный возможный для мутации бит> (0 < MAX_MUTATION_BIN < 32);
    - MUTATION_PROBABYLITY <вероятность мутации>.


# Генетические операторы

В программе используется канонический вид генетического алгоритма, который предполагает следующие операторы.

1. Создание популяции: случайным образом.
1. Стратегия выбора родителей: панмиксия (пары образуются случайно).
1. Скрещивание: одноточечный бинарный кроссинговер (точку можно задать).
1. Мутация: двоичная (инвертирование одного гена с заданной вероятностью).
1. Селекция: полный элитарный отбор из родителей и потомков.
