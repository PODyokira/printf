#include "main.h"
int handle_write_char(char c, char buff[],
int flg, int wth, int prc, int syz)
{
int i = 0;
char pd = ' ';

UNUSED(prc);
UNUSED(syz);pd

if (flg & F_ZERO)
pd = '0';

buff[i++] = c;
buff[i] = '\0';

if (wth > 1)
{
buff[BUFF_syz - 1] = '\0';
for (i = 0; i < wth - 1; i++)
buff[BUFF_syz - i - 2] = pd;

if (flg & F_MINUS)
return (write(1, &buff[0], 1) +
write(1, &buff[BUFF_syz - i - 1], wth - 1));
else
return (write(1, &buff[BUFF_syz - i - 1], wth - 1) +
write(1, &buff[0], 1));
}

return (write(1, &buff[0], 1));
}

int write_number(int is_negative, int ind, char buff[],
int flg, int wth, int prc, int syz)
{
int len = BUFF_syz - ind - 1;
char pd = ' ', extra_c = 0;

UNUSED(syz);

if ((flg & F_ZERO) && !(flg & F_MINUS))
pd = '0';
if (is_negative)
extra_c = '-';
else if (flg & F_PLUS)
extra_c = '+';
else if (flg & F_SPACE)
extra_c = ' ';

return (write_num(ind, buff, flg, wth, prc,
len, pd, extra_c));
}

int write_num(int ind, char buff[],
int flg, int wth, int prec,
int len, char pd, char extra_c)
{
int i, pd_start = 1;

if (prec == 0 && ind == BUFF_syz - 2 && buff[ind] == '0' && wth == 0)
return (0);
if (prec == 0 && ind == BUFF_syz - 2 && buff[ind] == '0')
buff[ind] = pd = ' ';
if (prec > 0 && prec < len)
pd = ' ';
while (prec > len)
buff[--ind] = '0', len++;
if (extra_c != 0)
len++;
if (wth > len)
{
for (i = 1; i < wth - len + 1; i++)
buff[i] = pd;
buff[i] = '\0';
if (flg & F_MINUS && pd == ' ')
{
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
}
else if (!(flg & F_MINUS) && pd == ' ')
{
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
}
else if (!(flg & F_MINUS) && pd == '0')
{
if (extra_c)
buff[--pd_start] = extra_c;
return (write(1, &buff[pd_start], i - pd_start) +
write(1, &buff[ind], len - (1 - pd_start)));
}
}
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], len));
}

int write_unsgnd(int is_negative, int ind,
char buff[],
int flg, int wth, int prc, int syz)
{

int len = BUFF_syz - ind - 1, i = 0;
char pd = ' ';

UNUSED(is_negative);
UNUSED(syz);

if (prc == 0 && ind == BUFF_syz - 2 && buff[ind] == '0')
return (0); 

if (prc > 0 && prc < len)
pd = ' ';

while (prc > len)
{
buff[--ind] = '0';
len++;
}

if ((flg & F_ZERO) && !(flg & F_MINUS))
pd = '0';

if (wth > len)
{
for (i = 0; i < wth - len; i++)
buff[i] = pd;

buff[i] = '\0';

if (flg & F_MINUS)
{
return (write(1, &buff[ind], len) + write(1, &buff[0], i));
}
else
{
return (write(1, &buff[0], i) + write(1, &buff[ind], len));
}
}

return (write(1, &buff[ind], len));
}

int write_pointer(char buff[], int ind, int len,
int wth, int flg, char pd, char extra_c, int pd_start)
{
int i;

if (wth > len)
{
for (i = 3; i < wth - len + 3; i++)
buff[i] = pd;
buff[i] = '\0';
if (flg & F_MINUS && pd == ' ')
{
buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], len) + write(1, &buff[3], i - 3));
}
else if (!(flg & F_MINUS) && pd == ' ')
{
buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
}
else if (!(flg & F_MINUS) && pd == '0')
{
if (extra_c)
buff[--pd_start] = extra_c;
buff[1] = '0';
buff[2] = 'x';
return (write(1, &buff[pd_start], i - pd_start) +
write(1, &buff[ind], len - (1 - pd_start) - 2));
}
}
buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], BUFF_syz - ind - 1));
}
