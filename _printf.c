#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - new printf function
 *
 * @format: list of type
 *
 */
int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int i, number_char;
	char *string;

	va_start(ap, format); /* initialization */
	i = 0;
	length = 0;
	number_char = 0;
	/* while (format[length]) */
	/*	length++; */
	while (format[i] != '\0') /* != NULL && *(format + i) != '\0') */
	{
		switch (format[i])
		{
			case ('c'):
				printf("%c", va_arg(ap, int));
				number_char++;
				break;
			case ('i'):
				printf("%d", va_arg(ap, int));
				number_char++;
				break;
			case ('f'):
				printf("%f", va_arg(ap, double));
				number_char++;
				break;
			case ('s'):
				string = va_arg(ap, char *);
				if (!string)
				{
					printf("(nil)");
					break;
				}
				printf("%s", string);
				number_char += strlen(string);
				break;
		}
		i++;
	}
	va_end(ap); /* clean up */
	number_char++;
	return (number_char);
}
