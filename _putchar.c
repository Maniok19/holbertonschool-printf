#include "main.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _putchar - writes the character c to stdout using a buffer
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int index;

	if (c == -1 || index >= BUFFER_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (c != -1)
	{
		buffer[index++] = c;
	}
	return (1);
}

/**
 * _flush_buffer - flushes the buffer
 */
void _flush_buffer(void)
{
	_putchar(-1);
}
