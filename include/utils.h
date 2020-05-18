/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

int is_printable(char const *str);
int is_digit(char const *str);
int my_atoi(char const *str);
char *my_strstr(char *haystack, char *needle);
int my_strlen(char const *str);
char *my_strcat(char const *str1, char const *str2);
int my_strcspn(char const *str, char const *chars);
int my_strspn(char const *str, char const *chars);
char *my_strtok(char *str, const char *delim);
char *my_strtok_r(char *str, const char *delim, char **backup);
int my_strcmp(char const *str1, char const *str2);
void my_put_nbr(int number);
void remove_end_spaces(char *str);
char *my_strdup(char const *str);

#endif /* !UTILS_H_ */
