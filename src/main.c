/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include "my_sokoban.h"

int usage(int status)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t");
    my_putstr("map  file representing the warehouse map, containing ‘#’ for");
    my_putstr(" walls,\n\t\t‘P’ for the player, ‘X’ for boxes and ‘O’ for ");
    my_putstr("storage locations.\n");
    return status;
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        return usage(EXIT_SUCCESS);
    } else if (argc == 2) {
        return my_sokoban(argv[1]);
    } else {
        return usage(EXIT_ERROR);
    }
}
