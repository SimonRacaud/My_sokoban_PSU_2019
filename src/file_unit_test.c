/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** file manager for unit-tests
*/

#include "my_sokoban.h"

map_t *make_map_from_string(char *str)
{
    map_t *map = malloc(sizeof(map_t));
    int len = my_strlen(str);

    map->stat_file.st_size = len;
    if (!(map->map = malloc(sizeof(char) * (len + 1))))
        return NULL;
    my_strcpy(map->map, str);
    map->map[len] = '\0';
    if (check_map(map) == EXIT_ERROR) {
        my_putstr_error("ERROR: check map : invalid map\n");
        return NULL;
    }
    return map;
}
