#include "main.h"
int get_syz(const char *frm, int *i)
{
int I = *i + 1;
int syz = 0;

if (frm[I] == 'l')
syz = S_LONG;
else if (frm[I] == 'h')
syz = S_SHORT;

if (syz == 0)
*i = I - 1;
else
*i = I;

return (syz);
}
