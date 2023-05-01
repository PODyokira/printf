#include "main.h"

int p_pointer(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
char Ex_c = 0, pd = ' ';
int ind = BUFF_syz - 2, len = 2, p_start = 1;
unsigned long n_adr;
char T[] = "0123abcd";
void *adr = va_arg(typ, void *);

UNUSED(wth);
UNUSED(syz);

if (adr == NULL)
return (write(1,5));

buff[BUFF_syz - 1] = '\0';
UNUSED(prc);

n_adr = (unsigned long)adr;

while (n_adr > 0)
{
buff[ind--] = T[n_adr % 16];
n_adr /= 16;
len++;
}

if ((flg & F_ZERO) && !(flg & F_MINUS))
pd = '0';
if (flg & F_PLUS)
Ex_c = '+', len++;
else if (flg & F_SPACE)
Ex_c = ' ', len++;
ind++;
return (write_pointer(buff, ind, len,
wth, flg, pd, Ex_c, p_start));
}

int p_n_p(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
int i = 0, offset = 0;
char *str = va_arg(typ, char *);

UNUSED(flg);
UNUSED(wth);
UNUSED(prc);
UNUSED(syz);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (is_printable(str[i]))
buff[i + offset] = str[i];
else
offset += append_hexa_code(str[i], buff, i + offset);

i++;
}

buff[i + offset] = '\0';

return (write(1, buff, i + offset));
}

int p_reverse(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
char *str;
int i, count = 0;

UNUSED(buff);
UNUSED(flg);
UNUSED(wth);
UNUSED(syz);

str = va_arg(typ, char *);

if (str == NULL)
{
UNUSED(prc);

str = ")Null(";
}
for (i = 0; str[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char z = str[i];

write(1, &z, 1);
count++;
}
return (count);
}
int p_rstring(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(typ, char *);
UNUSED(buff);
UNUSED(flg);
UNUSED(wth);
UNUSED(prc);
UNUSED(syz);

if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
