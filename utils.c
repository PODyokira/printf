
#include "main.h"

/**
 * printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * A_hexaCD - Append ascci in hexadecimal code to buff
 * @buff: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int A_hexaCD(char ascii_code, char buff[], int i)
{
	char To[] = "0123456789ABCDEF";
	/* The hexa frm code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = To[ascii_code / 16];
	buff[i] = To[ascii_code % 16];

	return (3);
}

/**
 * digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * Cnv_syz_nbr - Casts a number to the specified syz
 * @num: Number to be casted.
 * @syz: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int Cnv_syz_nbr(long int num, int syz)
{
	if (syz == S_LONG)
		return (num);
	else if (syz == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * Cnv_syz_uns - Casts a number to the specified syz
 * @num: Number to be casted
 * @syz: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int Cnv_syz_uns(unsigned long int num, int syz)
{
	if (syz == S_LONG)
		return (num);
	else if (syz == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

