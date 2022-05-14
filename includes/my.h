/*
** EPITECH PROJECT, 2021
** MY.H
** File description:
** It's just all function's prototype of our library
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdio.h>

int my_atoi(char *str);
void my_putchar(char c);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char *src, int n);
int my_printf(char *s, ...);
char *new_put_nbr(int nb);
int puissance(int y);
char **str_to_array(char *map, char stop);
void my_fputstr(char const *str, char *file_name);
int my_count_split(char *argv, char char_);
char **my_malloc_tab(int colum, int lines);
char **my_split_tab(char *argv, char char_);
char *my_strcat_(char *dest, char src);
void my_print_tab(char **tab);
char *my_itoa(int nb);
char **my_split_tabn(char *argv, char char_);

#endif /* MY_H_ */
