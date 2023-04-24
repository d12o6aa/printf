#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
    va_list list;
    int i = 0, j, m = 0;
	format form[] = {
    {"%s", printf_string}, {"%c", printf_char},
    {"%%", printf_37},
    {"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
    {"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
    {"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
    {"%S", printf_exclusive_string}, {"%p", printf_pointer}
    };
    va_start(list, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (form[j].id[0] == format[i] && form[j].id[1] == format[i + 1])
			{
				m += form[j].f(list);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		m++;
		i++;
	}
	va_end(list);
	return (m);
}

