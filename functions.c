#include "main.h"

/** PRINT CHAR **|
/**
 * @typ: ARGUMENTS
 * @buff: BUFFER
 * @flg: FLAGS
 * @wth: WIDTH
 * @prc: PRECISION
 * @syz: SIZE
 **
 */
int p_char(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
char c = va_arg(typ, int);

return (handle_write_char(c, buff, flg, wth, prc, syz));
}
/** PRINT STRING **|
/**
 * @typ: ARGUMENTS
 * @buff: BUFFER
 * @flg: FLAGS
 * @wth: WIDTH
 * @prc: PRECISION
 * @syz: SIZE
 **
 */
int p_string(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
int len = 0, i;
char *str = va_arg(typ, char *);

UNUSED(buff);
UNUSED(flg);
UNUSED(wth);
UNUSED(prc);
UNUSED(syz);
if (str == NULL)
{
str = "(null)";
if (prc >= 6)
str = "      ";
}

while (str[len] != '\0')
len++;

if (prc >= 0 && prc < len)
len = prc;

if (wth > len)
{
if (flg & F_MINUS)
{
write(1, &str[0], len);
for (i = wth - len; i > 0; i--)
write(1, " ", 1);
return (wth);
}
else
{
for (i = wth - len; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], len);
return (wth);
}
}

return (write(1, str, len));
}
/** PERCENT SIGN **|
/**
 * @typ: ARGUMENTS
 * @buff: BUFFER
 * @flg: FLAGS
 * @wth: WIDTH
 * @prc: PRECISION
 * @syz: SIZE
 **
 */
int p_percent(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
UNUSED(typ);
UNUSED(buff);
UNUSED(flg);
UNUSED(wth);
UNUSED(prc);
UNUSED(syz);
return (write(1, "%%", 1));
}

/** PRINT INT **|
/**
 * @typ: ARGUMENTS
 * @buff: BUFFER
 * @flg: FLAGS
 * @wth: WIDTH
 * @prc: PRECISION
 * @syz: SIZE
 **
 */
int p_int(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
int i = BUFF_syz - 2;
int is_negative = 0;
long int n = va_arg(typ, long int);
unsigned long int num;

n = convert_syz_number(n, syz);

if (n == 0)
buff[i--] = '0';

buff[BUFF_syz - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num > 0)
{
buff[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_number(is_negative, i, buff, flg, wth, prc, syz));
}

/** PRINT BINARY **|
/**
 * @typ: ARGUMENTS
 * @buff: BUFFER
 * @flg: FLAGS
 * @wth: WIDTH
 * @prc: PRECISION
 * @syz: SIZE
 **
 */
int p_binary(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int cnt;

UNUSED(buff);
UNUSED(flg);
UNUSED(wth);
UNUSED(prc);
UNUSED(syz);

n = va_arg(typ, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, cnt = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];

write(1, &z, 1);
cnt++;
}
}
return (cnt);
}

