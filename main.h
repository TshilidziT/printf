#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int handleString(char *str);
int handlePercent(void);
int handleChar(int c);
int _putchar(char c);
int handleDefault(const char *format, int i);
char *int_to_str(int number);
void print_decimal(int number);
int _printBinary(unsigned int x, const char *conversionSpecifier);

#endif
