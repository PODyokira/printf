#include "main.h"
int get_prc(const char *frm, int *i, va_list list)
{
int I = *i + 1;
int prc = -1;

if (frm[I] != '.')
return (prc);

prc = 0;

for (I += 1; frm[I] != '\0'; I++)
{
if (is_digit(frm[I]))
{
prc *= 10;
prc += frm[I] - '0';
}
else if (frm[I] == '*')
{
I++;
prc = va_arg(list, int);
break;
}
else
break;
}

*i = I - 1;

return (prc);
}
