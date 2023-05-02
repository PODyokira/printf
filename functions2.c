
#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * P_p - Prints the value of a pointer variable
 * @typ: List a of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed.
 */
int P_p(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	char lherbaC = 0, pd = ' ';
	int ind = B_syz - 2, len = 2, pd_beg = 1; /* len=2, for '0x' */
	unsigned long num_addrs;
	char To[] = "0123456789abcdef";
	void *addrs = va_arg(typ, void *);

	UNUSED(wth);
	UNUSED(syz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[B_syz - 1] = '\0';
	UNUSED(prc);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = To[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		pd = '0';
	if (flg & F_PLUS)
		lherbaC = '+', len++;
	else if (flg & F_SPACE)
		lherbaC = ' ', len++;

	ind++;

	/*return (write(1, &buff[i], B_syz - i - 1));*/
	return (W_pointer(buff, ind, len,
		wth, flg, pd, lherbaC, pd_beg));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * P_n_p - Prints ascii codes in hexa of non printable chars
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_n_p(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	int i = 0, offset = 0;
	char *str = va_arg(typ, char *);

	UNUSED(flg);
	UNUSED(wth);
	UNUSED(prc);
	UNUSED(syz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += A_hexaCD(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * P_reverse - Prints reverse string.
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Numbers of chars printed
 */

int P_reverse(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wth);
	UNUSED(syz);

	str = va_arg(typ, char *);

	if (str == NULL)
	{
		UNUSED(prc);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * P_Rstring - Print a string in rot13.
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Numbers of chars printed
 */
int P_Rstring(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);
	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wth);
	UNUSED(prc);
	UNUSED(syz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

