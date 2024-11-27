#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
  * print_char - function that prints a character
  * @list: list of arguments
  * @flags: flags + ' ' '#'
  * Return: number of characters printed
  * Description: function that prints a character
  */
int print_char(va_list list, flags_t flags)
{
	(void)flags;
	_putchar(va_arg(list, int)); /* Affiche le caractère */
	return (1);
}
/**
 * print_string - function that prints a string
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: function that prints a string
 */
int print_string(va_list list, flags_t flags)
{
	int i;
	char *str = va_arg(list, char *);

	(void)flags;
	if (str == NULL)
		str = "(null)"; /* Gère le cas d'une chaîne NULL */
	for (i = 0; str[i]; i++)
		_putchar(str[i]); /* Affiche chaque caractère de la chaîne */
	return (i);
}
/**
 * print_percent - function that prints a percent sign
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: function that prints a percent sign
 */
int print_percent(va_list list, flags_t flags)
{
	(void)list;
	(void)flags;
	_putchar('%'); /* Affiche le signe pourcentage */
	return (1);
}
/**
 * print_number - function that prints a number
 * @n: number to print
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n; /* Gère les nombres négatifs */
		count++;
	}
	if (n / 10)
		count += print_number(n / 10); /* Appel récursif pour les chiffres */
	_putchar(n % 10 + '0'); /* Affiche le dernier chiffre */
	return (count + 1);
}
/**
 * print_int - function that prints an integer
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: function that prints an integer
 */
int print_int(va_list list, flags_t flags)
{
	int digit = va_arg(list, int);
	int count = 0;

	if (digit >= 0 && flags.plus == 1)
	{
		_putchar('+'); /* Ajoute un signe plus si demandé */
		count++;
	}
	if (digit >= 0 && flags.space == 1)
	{
		_putchar(' '); /* Ajoute un espace si demandé */
		count++;
	}
	if (digit == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		digit = 147483648; /* Gère le cas particulier de INT_MIN */
		count += 2;
	}
	count += print_number(digit); /* Affiche le nombre */
	return (count);
}
