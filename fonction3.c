#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_adress - prints the adress of a variable
 * @list: list of arguments
 * Return: number of characters printed
 * Description: prints the adress of a variable
 */
int print_adress(va_list list)
{
	unsigned long int num = va_arg(list, unsigned long int);
	int count = 0;
	int result[32];
	int i = 0;

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
