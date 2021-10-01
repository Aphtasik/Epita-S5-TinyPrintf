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
    if (n == 0)
    {
        putchar('0');
        return 1;
    }
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

int itaoi_handle_signed(int isSigned, int n, int base)
{
    if (isSigned == 1 && n < 0)
    {
        n = -n;
        putchar('-');
        return my_itoa_base(n, base) + 1;
    }
    else if (isSigned == 0 && n < 0)
    {
        n = -n;
        return my_itoa_base(n, base);
    }
    return my_itoa_base(n, base);
}

int print_string(char *s)
{
    if (s == NULL)
    {
        fputs("(null)", stdout);
        return 6;
    }
    else
    {
        fputs(s, stdout);
        return my_strlen(s);
    }
}

int tinyprintf(const char *format, ...)
{
    if (!format)
    {
        return 0;
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
            case 's':
                count += print_string(va_arg(ap, char*));
                break;
            case 'x':
                count+= itaoi_handle_signed(0, va_arg(ap, int), 16);
                break;
            case 'o':
                count+= itaoi_handle_signed(0, va_arg(ap, int), 8);
                break;
            case 'c':
                putchar(va_arg(ap, int));
                count++;
                break;
            case 'u':
                count+= itaoi_handle_signed(0, va_arg(ap, int), 10);
                break;
            case 'd':
                count+= itaoi_handle_signed(1, va_arg(ap, int), 10);
                break;
            default:
                putchar(format[i + 1]);
                count++;
                break;
            }
            i++;
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
