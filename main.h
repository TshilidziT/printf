#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int handleString(char *str);
int handlePercent(void);
int handleChar(int c);
int handleDefault(const char *format, int i);
char *int_to_str(int number);
void print_str(char *str);
void print_decimal(char specifier, int number);
char my_printf(const char *format, ...);
int _printBinary(unsigned int x, const char *conversionSpecifier);

#endif
