#include <stdio.h>
#include "main.h"

int main(void)
{
	printf("Hello, Holberton\n");
	_printf("Hello, Holberton\n");
	printf("Hello, %s\n", "Holberton");
	_printf("Hello, %s\n", "Holberton");
	printf("Hello, %c\n", 'H');
	_printf("Hello, %c\n", 'H');
	printf("Hello, %d\n", 972);
	_printf("Hello, %d\n", 972);
	_printf("Hello, %i\n", 972);
	printf("Hello, %i\n", 972);
	_printf("Hello, %d\n", -2147483648);
	printf("Hello, %d\n", -2147483648);
	printf("hello %r %r \n");
	_printf("hello %r %r \n");
	return (0);
}
