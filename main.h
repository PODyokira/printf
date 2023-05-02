#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define B_syz 1024

/* flg */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* syzS */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The frm.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The frm.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *frm, ...);
int handle_P(const char *fmt, int *i,
va_list list, char buff[], int flg, int wth, int prc, int syz);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int P_char(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);
int P_string(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);
int P_percent(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);

/* Functions to print numbers */
int P_int(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);
int P_binary(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);
int P_unsigned(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);
int P_octal(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);
int P_hexaDe(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);
int P_hexaUp(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);

int P_hexa(va_list typ, char To[],
char buff[], int flg, char flag_ch, int wth, int prc, int syz);

/* Function to print non printable characters */
int P_n_p(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);

/* Funcion to print memory address */
int P_p(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);

/* Funciotns to handle other specifiers */
int get_flg(const char *frm, int *i);
int get_wth(const char *frm, int *i, va_list list);
int get_prc(const char *frm, int *i, va_list list);
int get_syz(const char *frm, int *i);

/*Function to print string in reverse*/
int P_reverse(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);

/*Function to print a string in rot 13*/
int P_Rstring(va_list typ, char buff[],
	int flg, int wth, int prc, int syz);

/* wth handler */
int H_writeC(char c, char buff[],
	int flg, int wth, int prc, int syz);
int W_numb(int positive, int ind, char buff[],
	int flg, int wth, int prc, int syz);
int W_number(int ind, char bff[], int flg, int wth, int prc,
	int len, char pd, char lherbaC);
int W_pointer(char buff[], int ind, int len,
	int wth, int flg, char pd, char lherbaC, int pd_beg);

int W_unsgnd(int negative, int ind,
char buff[],
	int flg, int wth, int prc, int syz);

/****************** UTILS ******************/
int printable(char);
int A_hexaCD(char, char[], int);
int digit(char);

long int Cnv_syz_nbr(long int num, int syz);
long int Cnv_syz_uns(unsigned long int num, int syz);

#endif /* MAIN_H */

