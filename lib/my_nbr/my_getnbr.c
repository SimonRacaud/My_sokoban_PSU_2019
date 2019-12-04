/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Task05 - Returns a number, sent to the function as a string
*/

#include "my_nbr.h"

static char define_symbol(int const i_first_nbr, char const *str)
{
    int nb_n = 0;

    for (int i = (i_first_nbr - 1); i >= 0; i--) {
        if (str[i] == '-')
            nb_n++;
        else if (str[i] != '+')
            break;
    }
    if (nb_n % 2 != 0)
        return '-';
    return '+';
}

static int check_toobig(char const *str, int size_nbr, char symb)
{
    char max_nbr_pos[10] = "2147483647";
    char max_nbr_neg[10] = "2147483648";

    for (int i = 0; i < size_nbr; i++) {
        if (symb == '+' && *(str + i) > max_nbr_pos[i]) {
            return (1);
        } else if (symb == '-' && *(str + i) > max_nbr_neg[i]) {
            return (1);
        }
        if (*(str + i) < max_nbr_pos[i])
            return (0);
    }
    return (0);
}

static void get_data_nbr(char const *str, int *i_first_nbr, int *size_nbr)
{
    int i = 0;

    while (*(str + i) != '\0') {
        if (*i_first_nbr != -1 && *(str + i) >= '0' && *(str + i) <= '9') {
            (*size_nbr)++;
        } else if (*(str + i) >= '1' && *(str + i) <= '9') {
            *i_first_nbr = i;
            (*size_nbr)++;
        }
        if (*i_first_nbr != (-1) && (*(str + i) < '0' || *(str + i) > '9'))
            break;
        i++;
    }
}

int my_getnbr(char const *str)
{
    int i_first_nbr = -1;
    int size_nb = 0;
    char symb = '+';
    int nbr = 0;

    get_data_nbr(str, &i_first_nbr, &size_nb);
    symb = define_symbol(i_first_nbr, str);
    if (size_nb > 10)
        return (0);
    if (size_nb == 10) {
        if (check_toobig((str + i_first_nbr), size_nb, symb) == 1)
            return (0);
    }
    for (int i = 0; i < size_nb; i++)
        nbr += (str[i + i_first_nbr] - '0') * my_power_rec(10, size_nb - i - 1);
    if (symb == '-')
        return (-nbr);
    else
        return (nbr);
}
