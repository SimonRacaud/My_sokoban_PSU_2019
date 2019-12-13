/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include "my_sokoban.h"

const int MAX_MAP = 4;
static const char *MAP[5] =
{
    "maps/map00",
    "maps/map01",
    "maps/map02",
    "maps/map03",
    "maps/map04"
};

int usage(int status)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\t");
    my_putstr("map  file representing the warehouse map, containing '#' for");
    my_putstr(" walls,\n\t\t'P' for the player, 'X' for boxes and 'O' for ");
    my_putstr("storage locations.\n");
    return status;
}

int main(int argc, char **argv)
{
    int id_map;
    int ret;

    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        return usage(EXIT_SUCCESS);
    } else {
        id_map = main_menu();
        if (id_map == EXIT || id_map > MAX_MAP)
            return EXIT_SUCCESS;
        ret = my_sokoban(MAP[id_map]);
        if (ret == EXIT_ERROR)
            return ret;
        main(argc, argv);
    }
}
