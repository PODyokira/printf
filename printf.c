
#include "main.h"

void print_buff(char buff[], int *buff_ind);

/**
 * _printf - Printf function.
 * @frm: frm.
 * Return: Printed chars.
 */
int _printf(const char *frm, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flg, wth, prc, syz, buff_ind = 0;
	va_list list;
	char buff[B_syz];

	if (frm == NULL)
		return (-1);

	va_start(list, frm);

	for (i = 0; frm && frm[i] != '\0'; i++)
	{
		if (frm[i] != '%')
		{
			buff[buff_ind++] = frm[i];
			if (buff_ind == B_syz)
				print_buff(buff, &buff_ind);
			/* write(1, &frm[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buff(buff, &buff_ind);
			flg = get_flg(frm, &i);
			wth = get_wth(frm, &i, list);
			prc = get_prc(frm, &i, list);
			syz = get_syz(frm, &i);
			++i;
			printed = handle_P(frm, &i, list, buff,
				flg, wth, prc, syz);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buff(buff, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buff - Prints the contents of the buff if it exist
 * @buff: Array of chars
 * @buff_ind: Index at which to add next char, represents the len.
 */
void print_buff(char buff[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buff[0], *buff_ind);

	*buff_ind = 0;
}

