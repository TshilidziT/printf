#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
int handleChar(int c);
int handleString(char *str);
int handlePercent(void);
int handleDefault(const char *format, int i);

#endif
