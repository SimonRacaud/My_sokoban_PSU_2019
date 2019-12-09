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

void clean_char(map_t *map)
{
    for (int i = 0; i < map->size - 1; i++) {
        if (map->map[i] == 'P' || map->map[i] == 'X')
            map->map[i] = ' ';
    }
}

int my_sokoban(char *path_map)
{
    map_t *map = read_map(path_map);
    int ret;

    if (!map)
        return EXIT_ERROR;
    ret = run(map);
    clean(map);
    if (ret == EXIT_RELOAD) {
        ret = my_sokoban(path_map);
    }
    return ret;
}
