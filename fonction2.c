#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_unsigned - function that prints an unsigned integer
 * @list: list of arguments
 * Return: number of characters printed
 */
int print_unsigned(va_list list)
{
	unsigned int digit = va_arg(list, unsigned int);
	unsigned int temp = 0;
	unsigned int power = 1;
	int count = 0;

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
int print_octal(va_list list)
{
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
int print_hex(va_list list)
{
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
int print_HEX(va_list list)
{
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
