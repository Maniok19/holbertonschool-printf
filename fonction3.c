#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_address - prints the adress of a variable
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: prints the adress of a variable
 */
int print_address(va_list list, flags_t flags)
{
	unsigned long num;
	int count = 0;
	int result[32];
	int i = 0;

	(void)flags;
	num = va_arg(list, unsigned long);
	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		_putchar('0');
		_putchar('x');
		count += 2;
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
 * print_binary - function that prints a binary
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: function that prints a binary
 */
int print_binary(va_list list, flags_t flags)
{
	unsigned int num = va_arg(list, unsigned int);
	int count = 0;
	int result[32];
	int i = 0;

	(void)flags;
	if (num <= 0)
	{
		_putchar(num + '0');
		count++;
	}
	else
	{
		while (num > 0)
		{
			result[i] = (num % 2);
			num = num / 2;
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
