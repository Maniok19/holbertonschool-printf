#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, j = 0, count = 0;
	flags_t flags = {0, 0, 0};
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
		{"p", print_adress},
		{NULL, NULL}
	};

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (format_list[j].type)
			{
				if (format_list[j].type[0] == format[i + 1])
				{
					count += format_list[j].f(list);
					i++;
					break;
				}
				j++;
			}
			if (format_list[j].type == NULL)
            {
                _putchar('%');
                _putchar(format[i + 1]);
                count += 2;
                i++;
            }
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
