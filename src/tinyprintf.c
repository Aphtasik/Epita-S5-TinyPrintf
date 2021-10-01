#include "tinyprintf.h"
#include <stdio.h>

int my_strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char convertToDec(int n)
{
    if (n >= 0 && n <= 9)
    {
        return (n + '0');
    }
    return (n + 'a' - 10);
}

void reverseString(char *s)
{
    int len = my_strlen(s);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int my_itoa_base(int n, int base)
{
    char s[512];
    int i = 0;

    while (n > 0)
    {
        s[i++] = convertToDec(n % base);
        n/= base;
    }
    s[i] = '\0';

    reverseString(s);
    fputs(s, stdout);
    return my_strlen(s);
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
            case 'x':
                s = va_arg(ap, int);
                count+= my_itoa_base(s, 16);
                i++;
                break;
            case 'o':
                s = va_arg(ap, int);
                count+= my_itoa_base(s, 8);
                i++;
                break;
            case 'c':
                s = va_arg(ap, int);
                fputc((s + '0'), stdout);
                i+=1;
                break;
            case 'u':
                s = va_arg(ap, int);
                count+= my_itoa_base(s, 10);
                i++;
                break;
            case 'd':
                s = va_arg(ap, int);
                count+= my_itoa_base(s, 10);
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
