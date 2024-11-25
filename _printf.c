#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_char - function that prints a character
 * @list: list of arguments
 * Return: number of characters printed
 * Description: function that prints a character
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
/**
 * print_string - function that prints a string
 * @list: list of arguments
 * Return: number of characters printed
 * Description: function that prints a string
 */
int print_string(va_list list)
{
	int i;
	char *str = va_arg(list, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
/**
 * print_percent - function that prints a percent sign
 * @list: list of arguments
 * Return: number of characters printed
 * Description: function that prints a percent sign
 */
int print_percent(va_list list)
{
	(void)list;
	_putchar('%');
	return (1);
}

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, j = 0, count = 0;
	print_t format_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
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
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(list);
	return (count);
}
