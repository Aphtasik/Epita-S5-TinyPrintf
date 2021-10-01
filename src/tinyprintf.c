#include "tinyprintf.h"
#include <stdio.h>

int tinyprintf(const char *format, ...)
{
    if (!format)
    {
        return 0; //TODO: Changer ce cas
    }

    va_list ap;
    va_start(ap, format);

    int count = 0;
    int i = 0;

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            switch (format[i + 1])
            {
            default:
                i++;
                putchar(format[i]);
                count++;
                break;        
            }
        }
        else
        {
            count++;
            putchar(format[i]);
        }
        i++;
    }

    va_end(ap);
    return count;
}
