#include "main.h"
int H_p(const char *fmt, int *ind, va_list list, char buff[],
	int flg, int wth, int prc, int syz)
{
int i, uk_len = 0, pd_chars = -1;
fmt_t fmt_types[] = {
{'c', p_char}, {'s', p_string}, {'%', p_percent},
{'i', p_int}, {'d', p_int}, {'b', p_binary},
{'u', p_unsigned}, {'o', p_octal}, {'x', p_hexaD},
{'X', p_hexaU}, {'p', p_pointer}, {'S', p_n_p},
{'r', p_reverse}, {'R', p_rstring}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmt != '\0'; i++)
if (fmt[*ind] == fmt_types[i].fmt)
return (fmt_types[i].fn(list, buff, flg, wth, prc, syz));

if (fmt_types[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
uk_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
uk_len += write(1, " ", 1);
else if (wth)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
uk_len += write(1, &fmt[*ind], 1);
return (uk_len);
}
return (pd_chars);
}
