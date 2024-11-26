#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
/**
 * struct print - struct for printf
 * @type: type of data
 * @f: function pointer
 * Description: struct for printf
 */
typedef struct print
{
	char *type;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(va_list list);
int print_int(va_list list);
int print_binary(va_list list);

#endif
