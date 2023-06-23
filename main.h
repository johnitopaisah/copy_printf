#ifndef "MAIN_H"
#define "MAIN_H"

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAG MACROS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES MACROS */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - the struct op
 * @fmt: The format.
 * @fn: The function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - the struct op
 * @fmt: format
 * @fn: the function associated
 */
typedef  struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/***************ALL THE FUNCTIONS***************/

/* Helper function for the _printf() */
void printf_buffer(char buffer[], int *buff_ind);

/* Function to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

#endif "MAIN_H"
