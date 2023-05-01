#include "main.h"
int get_wth(const char *frm, int *i, va_list list)
{
int I;
int wth = 0;

for (I = *i + 1; frm[I] != '\0'; I++)
{
if (is_digit(frm[I]))
{
wth *= 10;
wth += frm[I] - '0';
}
else if (frm[I] == '*')
{
I++;
wth = va_arg(list, int);
break;
}
else
break;
}

*i = I - 1;

return (wth);
}
