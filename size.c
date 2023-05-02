
#include "main.h"

/**
 * get_syz - Calculates the syz to cast the argument
 * @frm: frmted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: prc.
 */
int get_syz(const char *frm, int *i)
{
	int curr_i = *i + 1;
	int syz = 0;

	if (frm[curr_i] == 'l')
		syz = S_LONG;
	else if (frm[curr_i] == 'h')
		syz = S_SHORT;

	if (syz == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (syz);
}

