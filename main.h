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
	int (*f)(va_list, flags_t);
} print_t;
/**
 * struct flags - struct for flags
 * @plus: plus flag
 * @space: space flag
 * @hash: hash flag
 * Description: struct for flags
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(va_list list);
int print_int(va_list list);
int print_binary(va_list list);
int print_unsigned(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
void _flush_buffer(void);
int print_Sstring(va_list list);
int print_adress(va_list list);

#endif
