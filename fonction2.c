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
