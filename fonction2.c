#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_unsigned - function that prints an unsigned integer
 * @list: list of arguments
 * Return: number of characters printed
 */
int print_unsigned(va_list list, flags_t flags)
{
	unsigned int digit = va_arg(list, unsigned int);
	unsigned int temp = 0;
	unsigned int power = 1;
	int count = 0;
		if (digit >= 0 && flags.plus == 1)
	{
		_putchar('+');
		count++;
	}
	if (digit >= 0 && flags.space == 1 && flags.plus == 0)
	{
		_putchar(' ');
		count++;
	}

	if (list == NULL)
		return (0);
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
/**
 * print_octal - function that prints an octal
 * @list: list of arguments
 * Return: number of characters printed
 * Description: function that prints an octal
 */
int print_octal(va_list list, flags_t flags)
{
	(void)flags;
	unsigned int num = va_arg(list, unsigned int);
	int count = 0;
	int result[32];
	int i = 0;

	if (num <= 0)
	{
		_putchar(num + '0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			result[i] = (num % 8);
			num = num / 8;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			_putchar(result[i] + '0');
			count++;
		}
	}
	return (count);
}
/**
 * print_hex - function that prints a hexadecimal
 * @list: list of arguments
 * Return: number of characters printed
 * Description: function that prints a hexadecimal
 */
int print_hex(va_list list, flags_t flags)
{
	(void)flags;
	unsigned int num = va_arg(list, unsigned int);
	int count = 0;
	int result[32];
	int i = 0;

	if (num <= 0)
	{
		_putchar(num + '0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			result[i] = (num % 16);
			num = num / 16;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			if (result[i] < 10)
				_putchar(result[i] + '0');
			else
				_putchar(result[i] - 10 + 'a');
			count++;
		}
	}
	return (count);
}
/**
 * print_HEX - function that prints a hexadecimal
 * @list: list of arguments
 * Return: number of characters printed
 */
int print_HEX(va_list list, flags_t flags)
{
	(void)flags;
	unsigned int num = va_arg(list, unsigned int);
	int count = 0;
	int result[32];
	int i = 0;

	if (num <= 0)
	{
		_putchar(num + '0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			result[i] = (num % 16);
			num = num / 16;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			if (result[i] < 10)
				_putchar(result[i] + '0');
			else
				_putchar(result[i] - 10 + 'A');
			count++;
		}
	}
	return (count);
}
/**
 * print_Sstring - function that prints a string
 * @list: list of arguments
 * Return: number of characters printed
 */
int print_Sstring(va_list list, flags_t flags)
{
	(void)flags;
	char *str = va_arg(list, char *);
	int count = 0;
	int i = 0;

	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i])
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_HEX(list);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
		i++;
	}
	return (count);
}
