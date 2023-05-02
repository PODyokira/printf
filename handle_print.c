
#include "main.h"
/**
 * handle_P - Prints an argument based on its type
 * @fmt: frmted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buff: buff array to handle print.
 * @flg: Calculates active flg
 * @wth: get wth.
 * @prc: prc specification
 * @syz: syz specifier
 * Return: 1 or 2;
 */
int handle_P(const char *fmt, int *ind, va_list list, char buff[],
	int flg, int wth, int prc, int syz)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_typ[] = {
		{'c', P_char}, {'s', P_string}, {'%', P_percent},
		{'i', P_int}, {'d', P_int}, {'b', P_binary},
		{'u', P_unsigned}, {'o', P_octal}, {'x', P_hexaDe},
		{'X', P_hexaUp}, {'p', P_p}, {'S', P_n_p},
		{'r', P_reverse}, {'R', P_Rstring}, {'\0', NULL}
	};
	for (i = 0; fmt_typ[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_typ[i].fmt)
			return (fmt_typ[i].fn(list, buff, flg, wth, prc, syz));

	if (fmt_typ[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wth)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

