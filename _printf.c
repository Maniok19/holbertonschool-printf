#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * init_flags - initialise flags
 * @flags: structure containing '+', ' ', '#'
 */
void init_flags(flags_t *flags)
{
	flags->plus = 0;  /* Initialise le drapeau '+' */
	flags->space = 0; /* Initialise le drapeau espace */
	flags->hash = 0;  /* Initialise le drapeau '#' */
}
/**
 * set_flags - define flags
 * @format: format string
 * @i: pointeur to the index
 * @flags: structure containing flags '+', ' ', '#'
 */
void set_flags(const char *format, int *i, flags_t *flags)
{
	while (format[*i] == ' ' || format[*i] == '+' || format[*i] == '#')
	{
		if (format[*i] == ' ')
			flags->space = 1; /* Active le drapeau espace */
		if (format[*i] == '+')
			flags->plus = 1;  /* Active le drapeau '+' */
		if (format[*i] == '#')
			flags->hash = 1;  /* Active le drapeau '#' */
		(*i)++;               /* Avance à la prochaine position */
	}
}
/**
 * handle_length_modifier - handle length modifiers
 * @format: format string
 * @i: pointer to the index
 * @length: pointer to the length modifier
 */
void handle_length_modifier(const char *format, int *i, char *length)
{
	if (format[*i] == 'l' || format[*i] == 'h')
	{
		*length = format[*i];
		(*i)++;
	}
}
/**
 * handle_format - handle format
 * @format: format string
 * @list: arguments list
 * @flags: structure containing flags '+', ' ', '#'
 * @i: pointeur to the index
 * Return: number of printed characters
 */
int handle_format(const char *format, va_list list, flags_t flags, int *i)
{
	int j = 0, count = 0;
	char length = '\0';
	print_t format_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_Sstring},
		{"p", print_address},
		{NULL, NULL}
	};

	handle_length_modifier(format, i, &length);
	while (format_list[j].type)
	{
		if (format_list[j].type[0] == format[*i])
		{
			count += format_list[j].f(list, flags); /* Appelle la fonction */
			break;
		}
		j++;
	}
	if (format_list[j].type == NULL)
	{
		_putchar('%');        /* Imprime '%' si aucun format correspondant */
		_putchar(format[*i]); /* Imprime le caractère non reconnu */
		count += 2;           /* Incrémente le compteur de 2 */
	}
	return (count);
}

/**
 * _printf - fonction thant produce output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, count = 0;
	flags_t flags;

	if (format == NULL)
		return (-1);          /* Retourne -1 si format est NULL */

	va_start(list, format);   /* Initialise la liste d'arguments variables */
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;              /* Passe au caractère suivant après '%' */
			if (format[i] == '\0')
			{
				va_end(list);
				return (-1);  /* Retourne -1 si '%' est le dernier caractère */
			}
			init_flags(&flags);           /* Initialise les drapeaux */
			set_flags(format, &i, &flags);/* Définit les drapeaux */
			count += handle_format(format, list, flags, &i); /* Gère le format */
			init_flags(&flags);           /* Réinitialise les drapeaux */
		}
		else
		{
			_putchar(format[i]); /* Imprime le caractère normal */
			count++;             /* Incrémente le compteur */
		}
		i++;                     /* Passe au caractère suivant */
	}

	va_end(list);               /* Nettoie la liste d'arguments variables */
	_flush_buffer();            /* Vide le tampon */
	return (count);             /* Retourne le nombre total de caractères */
}
