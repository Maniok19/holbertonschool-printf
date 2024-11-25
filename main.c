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
	return (0);
}
