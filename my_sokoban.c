/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include "my_sokoban.h"

void clean(map_t *map)
{
    free(map->box_pos);
    free(map->map);
    free(map);
}

int my_sokoban(char *path_map)
{
    map_t *map = read_map(path_map);

    if (!map)
        return EXIT_ERROR;
    run(map);
    clean(map);
    return EXIT_SUCCESS;
}
