#include "main.h"
int get_F(const char *frm, int *i)
{
int j, I;
int flags = 0;
const char F_Ch[] = {'-', '+', '0', '#', ' ', '\0'};
const int F_Arr[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (I = *i + 1; frm[I] != '\0'; I++)
{
for (j = 0; F_Ch[j] != '\0'; j++)
if (frm[I] == F_Ch[j])
{
flags |= F_Arr[j];
break;
}

if (F_Ch[j] == 0)
break;
}

*i = I - 1;

return (flags);
}
