
#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * P_char - Prints a char
 * @typ: List a of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_char(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	char c = va_arg(typ, int);

	return (H_writeC(c, buff, flg, wth, prc, syz));
}
/************************* PRINT A STRING *************************/
/**
 * P_string - Prints a string
 * @typ: List a of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth.
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_string(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	int len = 0, i;
	char *str = va_arg(typ, char *);

	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wth);
	UNUSED(prc);
	UNUSED(syz);
	if (str == NULL)
	{
		str = "(null)";
		if (prc >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (prc >= 0 && prc < len)
		len = prc;

	if (wth > len)
	{
		if (flg & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = wth - len; i > 0; i--)
				write(1, " ", 1);
			return (wth);
		}
		else
		{
			for (i = wth - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (wth);
		}
	}

	return (write(1, str, len));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * P_percent - Prints a percent sign
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth.
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_percent(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	UNUSED(typ);
	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wth);
	UNUSED(prc);
	UNUSED(syz);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * P_int - Print int
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth.
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_int(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	int i = B_syz - 2;
	int negative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = Cnv_syz_nbr(n, syz);

	if (n == 0)
		buff[i--] = '0';

	buff[B_syz - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (W_numb(negative, i, buff, flg, wth, prc, syz));
}

/************************* PRINT BINARY *************************/
/**
 * P_binary - Prints an unsigned number
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth.
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Numbers of char printed.
 */
int P_binary(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wth);
	UNUSED(prc);
	UNUSED(syz);

	n = va_arg(typ, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

