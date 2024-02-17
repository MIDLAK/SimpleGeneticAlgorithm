#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* Логгирование как в файл, если path != NULL, так и в консоль */
void logg(const char *path, const char *format, ...) 
{
    va_list args;
    FILE *temp;

    /* логгирование в файл */
    if (path != NULL) {
        if ((temp = fopen(path, "a")) != NULL) {
            va_start(args, format);
            vfprintf(temp, format, args);
            va_end(args);
            fclose(temp);
        }
    }

    memset(args, 0, sizeof(args)); /* на всякий случай */
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}
