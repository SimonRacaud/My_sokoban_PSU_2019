/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** player management
*/

#include "my_sokoban.h"

int player_check_and_move(map_t *map, int key)
{
    int dst = get_destination(map, map->player_pos, key);
    int box_status = 0;

    if (dst == -1)
        return EXIT_ERROR;
    if (is_box_pos(dst, map->box_pos, map->nb_box))
        box_status = box_check_and_move(map, dst, key);
    if (map->map[dst] != '#') {
        if (box_status != EXIT_ERROR)
            map->player_pos = dst;
    }
    if (box_status == EXIT_END)
        return EXIT_END;
    return EXIT_SUCCESS;
}
