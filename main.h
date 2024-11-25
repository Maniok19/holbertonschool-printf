#ifndef MAIN_H
#define MAIN_H
/**
 * struct print - struct for printf
 * @type: type of data
 * @f: function pointer
 * Description: struct for printf
 */
typedef struct print
{
	char *type;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);


#endif
