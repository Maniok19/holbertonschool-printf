#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_unsigned - function that prints an unsigned integer
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 */
int print_unsigned(va_list list, flags_t flags)
{
	unsigned int digit = va_arg(list, unsigned int); /* Récupérer l'argument */
	unsigned int temp = 0; /* Variable temporaire */
	unsigned int power = 1; /* Puissance de 10 */
	int count = 0; /* Compteur de caractères */

	(void)flags; /* Ignorer les flags */
	temp = digit; /* Copier la valeur de digit */
	while (temp / 10) /* Calculer la puissance de 10 */
	{
		power *= 10; /* Multiplier power par 10 */
		temp /= 10; /* Diviser temp par 10 */
	}
	while (power > 0) /* Tant que power est supérieur à 0 */
	{
		_putchar(digit / power + '0'); /* Afficher le chiffre */
		digit %= power; /* Mettre à jour digit */
		power /= 10; /* Diviser power par 10 */
		count++; /* Incrémenter le compteur */
	}
	return (count); /* Retourner le nombre de caractères imprimés */
}
/**
 * print_octal - function that prints an octal
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: function that prints an octal
 */
int print_octal(va_list list, flags_t flags)
{
	unsigned int num = va_arg(list, unsigned int); /* Récupérer l'argument */
	int count = 0; /* Compteur de caractères */
	int result[32]; /* Tableau pour stocker les chiffres octaux */
	int i = 0; /* Indice du tableau */

	if (flags.hash && num != 0) /* Si le flag '#' est présent*/
	{
		_putchar('0'); /* Afficher '0' */
		count++; /* Incrémenter le compteur */
	}
	if (num == 0) /* Si num est égal à 0 */
	{
		_putchar('0'); /* Afficher '0' */
		count++; /* Incrémenter le compteur */
	}
	else
	{
		while (num > 0) /* Tant que num est supérieur à 0 */
		{
			result[i] = (num % 8); /* Stocker le reste de la division par 8 */
			num = num / 8; /* Diviser num par 8 */
			i++; /* Incrémenter l'indice */
		}
		for (i = i - 1; i >= 0; i--) /* Parcourir le tableau à l'envers */
		{
			_putchar(result[i] + '0'); /* Afficher le chiffre octal */
			count++; /* Incrémenter le compteur */
		}
	}
	return (count); /* Retourner le nombre de caractères imprimés */
}
/**
 * print_hex - function that prints a hexadecimal
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: function that prints a hexadecimal
 */
int print_hex(va_list list, flags_t flags)
{
	unsigned int digit = va_arg(list, unsigned int); /* Récupérer l'argument */
	int count = 0; /* Compteur de caractères */
	int result[32]; /* Tableau pour stocker les chiffres hexadécimaux */
	int i = 0; /* Indice du tableau */

	if (flags.hash && digit != 0) /* Si le flag '#' est présent */
	{
		_putchar('0'); /* Afficher '0' */
		_putchar('x'); /* Afficher 'x' */
		count += 2; /* Incrémenter le compteur de 2 */
	}
	if (digit == 0) /* Si digit est égal à 0 */
	{
		_putchar('0'); /* Afficher '0' */
		count++; /* Incrémenter le compteur */
	}
	else
	{
		while (digit > 0) /* Tant que digit est supérieur à 0 */
		{
			result[i] = (digit % 16); /* Stocker le reste de la division par 16 */
			digit = digit / 16; /* Diviser digit par 16 */
			i++; /* Incrémenter l'indice */
		}
		for (i = i - 1; i >= 0; i--) /* Parcourir le tableau à l'envers */
		{
			if (result[i] < 10)
				_putchar(result[i] + '0'); /* Afficher le chiffre hexadécimal */
			else
				_putchar(result[i] - 10 + 'a'); /* Afficher la lettre hexadécimale */
			count++; /* Incrémenter le compteur */
		}
	}
	return (count); /* Retourner le nombre de caractères imprimés */
}
/**
 * print_HEX - function that prints a hexadecimal
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 */
int print_HEX(va_list list, flags_t flags)
{
	unsigned int num = va_arg(list, unsigned int); /* Récupérer l'argument */
	int count = 0; /* Compteur de caractères */
	int result[32]; /* Tableau pour stocker les chiffres hexadécimaux */
	int i = 0; /* Indice du tableau */

	if (flags.hash && num != 0) /* Si le flag '#' est présent*/
	{
		_putchar('0'); /* Afficher '0' */
		_putchar('X'); /* Afficher 'X' */
		count += 2; /* Incrémenter le compteur de 2 */
	}
	if (num == 0) /* Si num est égal à 0 */
	{
		_putchar('0'); /* Afficher '0' */
		count++; /* Incrémenter le compteur */
	}
	else
	{
		while (num > 0) /* Tant que num est supérieur à 0 */
		{
			result[i] = (num % 16); /* Stocker le reste de la division par 16 */
			num = num / 16; /* Diviser num par 16 */
			i++; /* Incrémenter l'indice */
		}
		for (i = i - 1; i >= 0; i--) /* Parcourir le tableau à l'envers */
		{
			if (result[i] < 10)
				_putchar(result[i] + '0'); /* Afficher le chiffre hexadécimal */
			else
				_putchar(result[i] - 10 + 'A'); /* Afficher la lettre hexadécimale */
			count++; /* Incrémenter le compteur */
		}
	}
	return (count); /* Retourner le nombre de caractères imprimés */
}
/**
 * print_Sstring - function that prints a string
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 */
int print_Sstring(va_list list, flags_t flags)
{
	char *str = va_arg(list, char *); /* Récupérer l'argument */
	int count = 0; /* Compteur de caractères */
	int i = 0; /* Indice de la chaîne */

	(void)flags; /* Ignorer les flags */
	if (str == NULL) /* Si la chaîne est NULL */
	{
		str = "(null)"; /* Afficher "(null)" */
	}
	while (str[i]) /* Parcourir la chaîne */
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127) /* hors ASCII */
		{
			_putchar('\\'); /* Afficher '\' */
			_putchar('x'); /* Afficher 'x' */
			count += 2; /* Incrémenter le compteur de 2 */
			if ((str[i] / 16) < 10)
				_putchar((str[i] / 16) + '0'); /* Afficher le chiffre hexadécimal */
			else
				_putchar((str[i] / 16) - 10 + 'A'); /* Afficher la lettre hexadécimale */
			if ((str[i] % 16) < 10)
				_putchar((str[i] % 16) + '0'); /* Afficher le chiffre hexadécimal */
			else
				_putchar((str[i] % 16) - 10 + 'A'); /* Afficher la lettre hexadécimale */
			count += 2; /* Incrémenter le compteur de 2 */
		}
		else
		{
			_putchar(str[i]); /* Afficher le caractère */
			count++; /* Incrémenter le compteur */
		}
		i++; /* Incrémenter l'indice */
	}
	return (count); /* Retourner le nombre de caractères imprimés */
}
