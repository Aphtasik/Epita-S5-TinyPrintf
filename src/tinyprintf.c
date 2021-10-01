#include "tinyprintf.h"
#include <stdio.h>

int decimal(int val)
{
    int count = 0;
    int reversed = 0;
    int remainder = 0;
    char to_print;
    
    if (val == 0)
    {
        putchar('0');
        return 1;
    }
    if (val < 0)
    {
        putchar('-');
        val = -val;
        count++;
    }
    
    while (val != 0)
    {
        remainder = val % 10;
        reversed = reversed * 10 + remainder;
        val/= 10;
    }

    while (reversed != 0)
    {
        remainder = reversed % 10;
        to_print = remainder + '0';
        putchar(to_print);
        reversed/= 10;
        count++;
    }
    return count;
}

int tinyprintf(const char *format, ...)
{
    if (!format)
    {
        return 0; //TODO: Changer ce cas
    }

    va_list ap;
    va_start(ap, format);
    
    int s;
    int count = 0;
    int i = 0;

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            switch (format[i + 1])
            {
            case 'd':
               s = va_arg(ap, int);
               count+= decimal(s);
               i++;
               break;
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
