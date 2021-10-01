#include "../src/tinyprintf.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>


Test(basic, empty)
{
    cr_assert_eq(tinyprintf(""), 0);
}

Test(basic, copy)
{
    int res = tinyprintf("Il n'y a pas de directives\n");
    cr_assert_eq(res, 27, "GOT %d\n", res);
}

Test(error, null)
{
    cr_assert_eq(tinyprintf(NULL), 0);
}

Test(directive, percent)
{
    int res = tinyprintf("1%%1\n");
    cr_assert_eq(res, 4, "GOT %d\n", res);
}

Test(directive, decimal_positive)
{
    int res = tinyprintf("Nb: %d\n", 42);
    cr_assert_eq(res, 7, "GOT %d\n", res);
}

Test(directive, decimal_negative)
{
    int res = tinyprintf("Nb: %d\n", -42);
    cr_assert_eq(res, 8, "GOT %d\n", res);
}

Test(directive, decimal_zero)
{
    int res = tinyprintf("Nb: %d\n", 0);
    cr_assert_eq(res, 6, "GOT %d\n", res);
}

Test(directive, decimal_char)
{
    int res = tinyprintf("Nb: %d\n", '*');
    cr_assert_eq(res, 7, "GOT %d\n", res);
}

Test(directive, decimal_multiple_nb)
{
    int res = tinyprintf("%d%d%d\n", 1, -2, 3);
    cr_assert_eq(res, 5, "GOT %d\n", res);
}

Test(directive, char_unique)
{
    int res = tinyprintf("Ch: %c\n", '*');
    cr_assert_eq(res, 6, "GOT %c\n", res);
}

Test(directive, octal)
{
    int res = tinyprintf("Nb: %o\n", '7');
    cr_assert_eq(res, 6, "GOT %o\n", res);
}

Test(directive, string)
{
    int res = tinyprintf("%s\n", "oui");
    cr_assert_eq(res, 4, "GOT %c\n", res);
}


