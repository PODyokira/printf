#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * H_writeC - Prints a string
 * @c: char typ.
 * @buff: buff array to handle print
 * @flg:  Calculates active flg.
 * @wth: get wth.
 * @prc: prc specifier
 * @syz: syz specifier
 *
 * Return: Number of chars printed.
 */
int H_writeC(char c, char buff[],
	int flg, int wth, int prc, int syz)
{ /* char is stored at left and pdind at buff's right */
	int i = 0;
	char pd = ' ';

	UNUSED(prc);
	UNUSED(syz);

	if (flg & F_ZERO)
		pd = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (wth > 1)
	{
		buff[B_syz - 1] = '\0';
		for (i = 0; i < wth - 1; i++)
			buff[B_syz - i - 2] = pd;

		if (flg & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[B_syz - i - 1], wth - 1));
		else
			return (write(1, &buff[B_syz - i - 1], wth - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * W_numb - Prints a string
 * @negative: Lista of arguments
 * @ind: char typ.
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth.
 * @prc: prc specifier
 * @syz: syz specifier
 *
 * Return: Number of chars printed.
 */
int W_numb(int negative, int ind, char buff[],
	int flg, int wth, int prc, int syz)
{
	int len = B_syz - ind - 1;
	char pd = ' ', lherbaCh = 0;

	UNUSED(syz);

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		pd = '0';
	if (negative)
		lherbaCh = '-';
	else if (flg & F_PLUS)
		lherbaCh = '+';
	else if (flg & F_SPACE)
		lherbaCh = ' ';

	return (W_number(ind, buff, flg, wth, prc,
		len, pd, lherbaCh));
}

/**
 * W_number - Write a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buff: buff
 * @flg: flg
 * @wth: wth
 * @prec: prc specifier
 * @len: Number len
 * @pd: Pading char
 * @lherbaC: Extra char
 *
 * Return: Number of printed chars.
 */
int W_number(int ind, char buff[],
	int flg, int wth, int prec,
	int len, char pd, char lherbaC)
{
	int i, pd_beg = 1;

	if (prec == 0 && ind == B_syz - 2 && buff[ind] == '0' && wth == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == B_syz - 2 && buff[ind] == '0')
		buff[ind] = pd = ' '; /* wth is displayed with pding ' ' */
	if (prec > 0 && prec < len)
		pd = ' ';
	while (prec > len)
		buff[--ind] = '0', len++;
	if (lherbaC != 0)
		len++;
	if (wth > len)
	{
		for (i = 1; i < wth - len + 1; i++)
			buff[i] = pd;
		buff[i] = '\0';
		if (flg & F_MINUS && pd == ' ')/* Asign extra char to left of buff */
		{
			if (lherbaC)
				buff[--ind] = lherbaC;
			return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
		}
		else if (!(flg & F_MINUS) && pd == ' ')/* extra char to left of buff */
		{
			if (lherbaC)
				buff[--ind] = lherbaC;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
		}
		else if (!(flg & F_MINUS) && pd == '0')/* extra char to left of pd */
		{
			if (lherbaC)
				buff[--pd_beg] = lherbaC;
			return (write(1, &buff[pd_beg], i - pd_beg) +
				write(1, &buff[ind], len - (1 - pd_beg)));
		}
	}
	if (lherbaC)
		buff[--ind] = lherbaC;
	return (write(1, &buff[ind], len));
}

/**
 * W_unsgnd - Writes an unsigned number
 * @negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buff
 * @buff: Array of chars
 * @flg: flg specifiers
 * @wth: wth specifier
 * @prc: prc specifier
 * @syz: syz specifier
 *
 * Return: Number of written chars.
 */
int W_unsgnd(int negative, int ind,
	char buff[],
	int flg, int wth, int prc, int syz)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = B_syz - ind - 1, i = 0;
	char pd = ' ';

	UNUSED(negative);
	UNUSED(syz);

	if (prc == 0 && ind == B_syz - 2 && buff[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (prc > 0 && prc < len)
		pd = ' ';

	while (prc > len)
	{
		buff[--ind] = '0';
		len++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		pd = '0';

	if (wth > len)
	{
		for (i = 0; i < wth - len; i++)
			buff[i] = pd;

		buff[i] = '\0';

		if (flg & F_MINUS) /* Asign extra char to left of buff [buff>pd]*/
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], i));
		}
		else /* Asign extra char to left of pding [pd>buff]*/
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], len));
		}
	}

	return (write(1, &buff[ind], len));
}

/**
 * W_pointer - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buff
 * @len: len of number
 * @wth: Wwth specifier
 * @flg: flg specifier
 * @pd: Char representing the pding
 * @lherbaC: Char representing extra char
 * @pd_beg: Index at which pding should start
 *
 * Return: Number of written chars.
 */
int W_pointer(char buff[], int ind, int len,
	int wth, int flg, char pd, char lherbaC, int pd_beg)
{
	int i;

	if (wth > len)
	{
		for (i = 3; i < wth - len + 3; i++)
			buff[i] = pd;
		buff[i] = '\0';
		if (flg & F_MINUS && pd == ' ')/* Asign extra char to left of buff */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (lherbaC)
				buff[--ind] = lherbaC;
			return (write(1, &buff[ind], len) + write(1, &buff[3], i - 3));
		}
		else if (!(flg & F_MINUS) && pd == ' ')/* extra char to left of buff */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (lherbaC)
				buff[--ind] = lherbaC;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
		}
		else if (!(flg & F_MINUS) && pd == '0')/* extra char to left of pd */
		{
			if (lherbaC)
				buff[--pd_beg] = lherbaC;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[pd_beg], i - pd_beg) +
				write(1, &buff[ind], len - (1 - pd_beg) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (lherbaC)
		buff[--ind] = lherbaC;
	return (write(1, &buff[ind], B_syz - ind - 1));
}

