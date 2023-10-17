#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int handleChar(int c);
int handleString(char *str);
int handlePercent(void);
int handleDefault(const char *format, int i);
int _printf(const char *format, ...);
char *int_to_str(int num);
void print_decimal(char specifier, int number);
void print_str(char *str);


#endif
