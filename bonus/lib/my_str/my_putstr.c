/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Task02
*/

#include "my_str.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}
