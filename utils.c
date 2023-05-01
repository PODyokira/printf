#include "main.h"

int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

int append_hexa_code(char ascii_c, char buff[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_c < 0)
ascii_c *= -1;

buff[i++] = '\\';
buff[i++] = 'x';

buff[i++] = map_to[ascii_c / 16];
buff[i] = map_to[ascii_c % 16];

return (3);
}

int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

long int convert_size_number(long int n, int syz)
{
if (syz == S_LONG)
return (n);
else if (syz == S_SHORT)
return ((short)n);

return ((int)n);
}

long int convert_syz_unsgnd(unsigned long int n, int syz)
{
if (syz == S_LONG)
return (n);
else if (syz == S_SHORT)
return ((unsigned short)n);

return ((unsigned int)n);
}
