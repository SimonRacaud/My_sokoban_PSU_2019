/*
** EPITECH PROJECT, 2019
** my_put_str_error
** File description:
** write a string on the error output
*/

#include "my_str.h"
#include <unistd.h>

void my_putstr_error(char *str)
{
    write(2, str, my_strlen(str));
}
