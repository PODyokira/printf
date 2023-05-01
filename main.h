/* * */
#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAG */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE */
#define S_LONG 2
#define S_SHORT 1


struct Format
{
char Format;
int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct Format Format_t;

int _printf(const char *format, ...);
int handle_print(const char *Format, int *i,
va_list list, char buff[], int flg, int wth, int prc, int syz);

int p_char(va_list typ, char buff[],
int flg, int wth, int prc, int syz);
int p_string(va_list typ, char buff[],
int flg, int wth, int prc, int syz);
int p_percent(va_list typ, char buff[],
int flg, int wth, int prc, int syz);

int p_int(va_list typ, char buff[],
int flg, int wth, int prc, int syz);
int p_binary(va_list typ, char buff[],
int flg, int wth, int prc, int syz);
int p_unsigned(va_list typ, char buff[],
int flg, int wth, int prc, int syz);
int p_octal(va_list typ, char buff[],
int flg, int wth, int prc, int syz);
int p_hexaD(va_list typ, char buff[],
int flg, int wth, int prc, int syz);
int p_hexaU(va_list typ, char buff[],
int flg, int wth, int prc, int syz);

int p_hexa(va_list typ, char map_to[],
char buff[], int flg, char flag_ch, int wth, int prc, int syz);


int p_n_p(va_list typ, char buff[],
int flg, int wth, int prc, int syz);


int p_pointer(va_list typ, char buff[],
int flg, int wth, int prc, int syz);

int get_flg(const char *format, int *i);
int get_wth(const char *format, int *i, va_list list);
int get_prc(const char *format, int *i, va_list list);
int get_syz(const char *format, int *i);


int p_reverse(va_list typ, char buff[],
int flg, int wth, int prc, int syz);


int p_rstring(va_list typ, char buff[],
int flg, int wth, int prc, int syz);


int handle_write_char(char c, char buff[],
int flg, int wth, int prc, int syz);
int write_number(int is_positive, int ind, char buff[],
int flg, int wth, int prc, int syz);
int write_num(int ind, char bff[], int flg, int wth, int prc,
int len, char pd, char extra_c);
int write_pointer(char buff[], int ind, int len,
int wth, int flg, char pd, char extra_c, int pd_s);

int write_unsgnd(int is_negative, int ind,
char buff[],
int flg, int wth, int prc, int syz);


int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_syz_number(long int num, int syz);
long int convert_syz_unsgnd(unsigned long int num, int syz);

#endif 
/* * */
