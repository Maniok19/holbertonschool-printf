#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * init_flags - initializes flags
 * @flags: flags + ' ' '#'
 */
void init_flags(flags_t *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
}
/**
 * set_flags - sets flags
 * @format: character string
 * @i: index
 * @flags: flags + ' ' '#'
 */
void set_flags(const char *format, int *i, flags_t *flags)
{
	while (format[*i] == ' ' || format[*i] == '+' || format[*i] == '#')
	{
		if (format[*i] == ' ')
			flags->space = 1;
		if (format[*i] == '+')
			flags->plus = 1;
		if (format[*i] == '#')
			flags->hash = 1;
		(*i)++;
	}
}
/**
 * handle_format - handles format
 * @format: character string
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * @i: index
 * Return: number of characters printed
 */
int handle_format(const char *format, va_list list, flags_t flags, int *i)
{
	int j = 0, count = 0;
	print_t format_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_Sstring},
		{"p", print_address},
		{NULL, NULL}
	};

	while (format_list[j].type)
	{
		if (format_list[j].type[0] == format[*i])
		{
			count += format_list[j].f(list, flags);
			break;
		}
		j++;
	}
	if (format_list[j].type == NULL)
	{
		_putchar('%');
		_putchar(format[*i]);
		count += 2;
	}
	return (count);
}

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, count = 0;
	flags_t flags;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(list);
				return (-1);
			}
			init_flags(&flags);
			set_flags(format, &i, &flags);
			count += handle_format(format, list, flags, &i);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(list);
	_flush_buffer();

	return (count);
}
