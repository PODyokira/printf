
#include "main.h"

/**
 * get_prc - Calculates the prc for printing
 * @frm: frmted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: prc.
 */
int get_prc(const char *frm, int *i, va_list list)
{
	int curr_i = *i + 1;
	int prc = -1;

	if (frm[curr_i] != '.')
		return (prc);

	prc = 0;

	for (curr_i += 1; frm[curr_i] != '\0'; curr_i++)
	{
		if (digit(frm[curr_i]))
		{
			prc *= 10;
			prc += frm[curr_i] - '0';
		}
		else if (frm[curr_i] == '*')
		{
			curr_i++;
			prc = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (prc);
}

