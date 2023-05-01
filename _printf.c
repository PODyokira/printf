#include "main.h"
void p_buff(char buff[], int *buff_ind);
/**
 * @frm: form.
 */
int Print_f(const char *frm, ...)
{
int i, p = 0, p_chars = 0;
int flg, wth, prc, syz, buff_ind = 0;
va_list l;
char buff[buff_syz];
if (frm == NULL)
return (-1);
va_start(l, frm);
for (i = 0; frm && frm[i] != '\0'; i++)
{
if (frm[i] != '%')
{
buff[buff_ind++] = frm[i];
if (buff_ind == buff_syz)
p_buff(buff, &buff_ind);
p_chars++;
}
else
{
p_buff(buff, &buff_ind);
flg = get_flg(frm, &i);
wth = get_wth(frm, &i, l);
prc = get_prc(frm, &i, l);
syz = get_syz(frm, &i);
++i;
p = handle_print(frm, &i, l, buff,
flg, wth, prc, syz);
if (p == -1)
return (-1);
p_chars += p;
}
}
p_buff(buff, &buff_ind);
va_end(l);
return (p_chars);
}

/**
 * @buff: Array of chars
 * @buff_ind: Index->Length
 */
void p_buff(char buff[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buff[0], *buff_ind);
*buff_ind = 0;
}
