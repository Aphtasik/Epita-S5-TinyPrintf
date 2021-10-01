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
    int res = tinyprintf("1%%1");
    cr_assert_eq(res, 3, "GOT %d\n", res);
}

Test(directive, percent_no_next_char)
{
    int res = tinyprintf("1%");
    cr_assert_eq(res, 0, "GOT %d\n", res);
}
