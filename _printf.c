#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 *
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
    va_list list ;
    
    int i=0, j, m=0;
    
    format form[] = {
        {"%s", printf_string},
        {"%c", printf_char},
        {"%%", printf_37},
        {"%i", printf_int},
        {"%R", printf_rot13},
        {"%S", printf_exclusive_string},
        {"%o", printf_oct},
        {"%p", printf_pointer},
        {"%X", printf_HEX},
        {"%u", printf_unsigned},
        {"%r", printf_srev},
        {"%d", printf_dec},
        {"%b", printf_bin},
        {"%x", printf_hex}
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
