#include <limits.h>
#include <stdio.h>
#include "main.h"
int main(void)
{
	int len = -2147483648;
	int len2;
	unsigned int ui;
	void *addr;

	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%%]\n");
	len2 = printf("Percent:[%%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%%!]\n");
	printf("Unknown:[%%!]\n");
	printf("Binary:[%b]\n", 98);
	_printf("Binary:[%b]\n", 98);
	printf("Binary:[%b]\n", 0);
	_printf("Binary:[%b]\n", 0);
	_printf("%S\n", "Holberton\nSchool");
	printf("%S\n", "Holberton\nSchool");
	printf("+++%shol+++%shol+++%shol+++\n", "hol", "hol", "hol");
	_printf("+++%shol+++%shol+++%shol+++\n", "hol", "hol", "hol");
	printf("####%p####%p####%p####\n", addr, addr, addr);
	_printf("####%p####%p####%p####\n", addr, addr, addr);
	len2 = printf("%");
	len =_printf("%");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	return (0);
}
