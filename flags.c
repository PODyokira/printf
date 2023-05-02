#include "main.h"

/**
 * get_flg - Calculates active flg
 * @frm: frmted string in which to print the arguments
 * @i: take a parameter.
 * Return: flg:
 */
int get_flg(const char *frm, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flg = 0;
	const char flg_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flg_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; frm[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; flg_CH[j] != '\0'; j++)
			if (frm[curr_i] == flg_CH[j])
			{
				flg |= flg_ARR[j];
				break;
			}

		if (flg_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flg);
}

