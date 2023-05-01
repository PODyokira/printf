#include "main.h"
int p_unsigned(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
int i = BUFF_syz - 2;
unsigned long int n = va_arg(typ, unsigned long int);

n = convert_syz_unsgnd(n, syz);

if (n == 0)
buff[i--] = '0';

buff[BUFF_syz - 1] = '\0';

while (n > 0)
{
buff[i--] = (n % 10) + '0';
n /= 10;
}

i++;

return (write_unsgnd(0, i, buff, flg, wth, prc, syz));
}

int p_octal(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{

int i = BUFF_syz - 2;
unsigned long int n = va_arg(typ, unsigned long int);
unsigned long int NN = n;

UNUSED(wth);

n = convert_syz_unsgnd(n, syz);

if (n == 0)
buff[i--] = '0';

buff[BUFF_syz - 1] = '\0';

while (n > 0)
{
buff[i--] = (n % 8) + '0';
n /= 8;
}

if (flg & FF && NN != 0)
buff[i--] = '0';

i++;

return (write_unsgnd(0, i, buff, flg, wth, prc, syz));
}
int p_hexaU(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
return (p_hexa(typ, "0123ABCD", buff,
flg, 'X', wth, prc, syz));
}

int p_hexaD(va_list typ, char buff[],
int flg, int wth, int prc, int syz)
{
return (p_hexa(typ, "0123456789abcdefghi", buff,
flg, 'x', wth, prc, syz));
}

int p_hexa(va_list typ, char map_to[], char buff[],
int flg, char flag_ch, int wth, int prc, int syz)
{
int i = BUFF_syz - 2;
unsigned long int n = va_arg(typ, unsigned long int);
unsigned long int NN = n;

UNUSED(wth);

n = convert_syz_unsgnd(n, syz);

if (n == 0)
buff[i--] = '0';

buff[BUFF_syz - 1] = '\0';

while (n > 0)
{
buff[i--] = map_to[n % 16];
n /= 16;
}

if (flg & FF && NN != 0)
{
buff[i--] = flag_ch;
buff[i--] = '0';
}

i++;

return (write_unsgnd(0, i, buff, flg, wth, prc, syz));
}
