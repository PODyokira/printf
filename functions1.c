
#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * P_unsigned - Prints an unsigned number
 * @typ: List a of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed.
 */
int P_unsigned(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	int i = B_syz - 2;
	unsigned long int num = va_arg(typ, unsigned long int);

	num = Cnv_syz_uns(num, syz);

	if (num == 0)
		buff[i--] = '0';

	buff[B_syz - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (W_unsgnd(0, i, buff, flg, wth, prc, syz));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * P_octal - Prints an unsigned number in octal notation
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_octal(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{

	int i = B_syz - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_n = num;

	UNUSED(wth);

	num = Cnv_syz_uns(num, syz);

	if (num == 0)
		buff[i--] = '0';

	buff[B_syz - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flg & F_HASH && init_n != 0)
		buff[i--] = '0';

	i++;

	return (W_unsgnd(0, i, buff, flg, wth, prc, syz));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * P_hexaDe - Prints an unsigned number in hexadecimal notation
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_hexaDe(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	return (P_hexa(typ, "0123456789abcdef", buff,
		flg, 'x', wth, prc, syz));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * P_hexaUp - Prints an unsigned number in upper hexadecimal notation
 * @typ: Lista of arguments
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * Return: Number of chars printed
 */
int P_hexaUp(va_list typ, char buff[],
	int flg, int wth, int prc, int syz)
{
	return (P_hexa(typ, "0123456789ABCDEF", buff,
		flg, 'X', wth, prc, syz));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * P_hexa - Prints a hexadecimal number in lower or upper
 * @typ: Lista of arguments
 * @To: Array of values to map the number to
 * @buff: buff array to handle print
 * @flg:  Calculates active flg
 * @flag_ch: Calculates active flg
 * @wth: get wth
 * @prc: prc specification
 * @syz: syz specifier
 * @syz: syz specification
 * Return: Number of chars printed
 */
int P_hexa(va_list typ, char To[], char buff[],
	int flg, char flag_ch, int wth, int prc, int syz)
{
	int i = B_syz - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_n = num;

	UNUSED(wth);

	num = Cnv_syz_uns(num, syz);

	if (num == 0)
		buff[i--] = '0';

	buff[B_syz - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = To[num % 16];
		num /= 16;
	}

	if (flg & F_HASH && init_n != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (W_unsgnd(0, i, buff, flg, wth, prc, syz));
}

