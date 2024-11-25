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
 * print_int - function that prints an integer
 * @list: list of arguments
 * Return: number of characters printed
 * Description: function that prints an integer
 */
int print_int(va_list list)
{
	int digit;
	int min = -2147483648;
	int count = 0;
	int temp = 0;
	int power = 1;

	if (list == NULL)
		return (0);
	if (digit == min)
	{
		_putchar('-');
		_putchar('2');
		digit = 147483648;
		count += 2;
	}
	digit = va_arg(list, int);
	if (digit < 0)
	{
		_putchar('-');
		digit = -digit;
		count++;
	}
	temp = digit;
	while (temp / 10)
	{
		power *= 10;
		temp /= 10;
	}
	while (power > 0)
	{
		_putchar(digit / power + '0');
		digit %= power;
		power /= 10;
		count++;
	}
	return (count);
}
