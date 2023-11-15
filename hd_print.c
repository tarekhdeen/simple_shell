#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * hd_print - print function
 * @format: a string
 */
void hd_print(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
