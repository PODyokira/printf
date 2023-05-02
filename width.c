#include "main.h"

/**
 * get_wth - Calculates the wth for printing
 * @frm: frmted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: wth.
 */
int get_wth(const char *frm, int *i, va_list list)
{
	int curr_i;
	int wth = 0;

	for (curr_i = *i + 1; frm[curr_i] != '\0'; curr_i++)
	{
		if (digit(frm[curr_i]))
		{
			wth *= 10;
			wth += frm[curr_i] - '0';
		}
		else if (frm[curr_i] == '*')
		{
			curr_i++;
			wth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (wth);
}

