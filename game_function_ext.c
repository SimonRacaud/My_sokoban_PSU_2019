/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game loop
*/

#include "my_sokoban.h"

int is_object_pos(int pos, int *list_obj_pos, int size_list)
{
    for (int i = 0; i < size_list; i++) {
        if (pos == list_obj_pos[i])
            return 1;
    }
    return 0;
}

int box_check_and_move(map_t *map, int pos, int key)
{
    int dst = get_destination(map, pos, key);
    int is_box_pos = is_object_pos(dst, map->box_pos, map->nb_box)

    if (!is_box_pos || map->map[dst] == ' ') {
        if (is_object_pos(dst, map->storage_pos, map->nb_storage))
            eval_game(map);
        move_char(map, pos, dst);
    }
    return 0;
}

void move_char(map_t *map, int src, int dest)
{

}

void eval_game(map_t *map)
{

}
