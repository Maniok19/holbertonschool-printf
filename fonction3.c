#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_address - prints the address of a variable
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 * Description: prints the address of a variable
 */
int print_address(va_list list, flags_t flags)
{
	unsigned long num; /* Déclaration de la variable num */
	int count = 0; /* Initialisation du compteur */
	int result[32]; /* Tableau pour stocker les résultats */
	int i = 0; /* Initialisation de l'index */

	(void)flags; /* Ignorer les flags */
	num = va_arg(list, unsigned long); /* Récupérer l'argument */
	if (num == 0) /* Si le nombre est 0 */
	{
		_putchar('('); /* Afficher '(' */
		_putchar('n'); /* Afficher 'n' */
		_putchar('i'); /* Afficher 'i' */
		_putchar('l'); /* Afficher 'l' */
		_putchar(')'); /* Afficher ')' */
		count += 5; /* Incrémenter le compteur de 5 */
	}
	else
	{
		_putchar('0'); /* Afficher 0 */
		_putchar('x'); /* Afficher x */
		count += 2; /* Incrémenter le compteur de 2 */
		while (num > 0) /* Tant que num est supérieur à 0 */
		{
			result[i] = (num % 16); /* Stocker le reste de la division par 16 */
			num = num / 16; /* Diviser num par 16 */
			i++; /* Incrémenter l'index */
		}
		for (i = i - 1; i >= 0; i--) /* Parcourir le tableau à l'envers */
		{
			if (result[i] < 10) /* Si le résultat est inférieur à 10 */
				_putchar(result[i] + '0'); /* Afficher le chiffre */
			else
				_putchar(result[i] - 10 + 'a'); /* Afficher la lettre correspondante */
			count++; /* Incrémenter le compteur */
		}
	}
	return (count); /* Retourner le compteur */
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
	unsigned int num = va_arg(list, unsigned int); /* Récupérer l'argument */
	int count = 0; /* Initialisation du compteur */
	int result[32]; /* Tableau pour stocker les résultats */
	int i = 0; /* Initialisation de l'index */

	(void)flags; /* Ignorer les flags */
	if (num == 0) /* Si le nombre est égal à 0 */
	{
		_putchar(num + '0'); /* Afficher le chiffre */
		count++; /* Incrémenter le compteur */
	}
	else
	{
		while (num > 0) /* Tant que num est supérieur à 0 */
		{
			result[i] = (num % 2); /* Stocker le reste de la division par 2 */
			num = num / 2; /* Diviser num par 2 */
			i++; /* Incrémenter l'index */
		}
		for (i = i - 1; i >= 0; i--) /* Parcourir le tableau à l'envers */
		{
			_putchar(result[i] + '0'); /* Afficher le chiffre */
			count++; /* Incrémenter le compteur */
		}
	}
	return (count); /* Retourner le compteur */
}
/**
 * print_rev - function that prints a string in reverse
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 */
int print_rev(va_list list, flags_t flags)
{
	char *str = va_arg(list, char *);
	int i, count = 0;

	(void)flags;
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
/**
 * print_rot13 - function that prints a string in rot13
 * @list: list of arguments
 * @flags: flags + ' ' '#'
 * Return: number of characters printed
 */
int print_rot13(va_list list, flags_t flags)
{
	char *str = va_arg(list, char *);
	int i, j, count = 0;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)flags;
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		j = 0;
		for (j = 0; alpha[j] != '\0'; j++)
		{
		if (str[i] == alpha[j])
		{
			_putchar(rot13[j]);
			count++;
		}
		}
	}
	return (count);
}
