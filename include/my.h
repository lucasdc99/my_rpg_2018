/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h for lib
*/

#ifndef MY_H_
#define MY_H_

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// String

void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_show_word_array(char *const *);
char **my_str_to_word_array(char *);
char *my_strdup(char const *);
char *my_itc(int nbr);
int my_contains(char *str, char c);
void my_memset(char *tab, int value, int size);
void my_memsetdouble(double *, int value , int size);

// NUMBER

int my_isneg(int);
void my_swap(int *, int *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
int my_put_nbr(int);
int my_putnbr_base(int, char *);
long my_putnbr_baselong(long, char *);
void my_put_float(double, int);
int my_put_nbru(unsigned int);

// OTHER

int find_str(char *str, char *to_find);
int overflow(char const *str);
int calc_rendu(int incr, int lenght, char const *str);
int my_power_it(int nb, int power);
int my_strlen2(char const *str);
void print_nbr(void);
int *check(int i, int *array);
int word_count_hand(char *str);
int is_numoralpha(char c);
int alpha(char const *, int);
int alpha2(char const *, int);
int alpha3(char const *, int);
int check1(char s1, char s2);
int my_is_prime_sup(int nb);
int my_length(char *str);

// MALLOC

char **my_malloc2d(int lines, int cols);
char *my_malloc(int size);
int **my_malloc2d_int(int lines, int cols);
short **my_malloc2d_short(int, int);

//FREE

void my_free2d(char **buffer, int cols);
void my_free2d_short(short **buffer, int cols);


// PRINTF

int (*ptr_fct[18])(va_list);
int my_printf(char *, ...);


// DISPLAY

int my_putchar_printf(va_list);
int my_put_percent(va_list);
int my_put_pointer(va_list);
int my_putstr_printf(va_list);
int my_putstr_printable(va_list);

int my_put_nbr_bin(va_list);
int my_put_octal(va_list);
int put_nothing(va_list);
int my_put_nbr_printf(va_list);
int my_put_nbr_hexmin(va_list);
int my_put_nbr_hexmaj(va_list);
int float_precision(va_list, int);
int my_put_nbr_unsigned(va_list);
int my_put_nbr_float(va_list);

#endif
