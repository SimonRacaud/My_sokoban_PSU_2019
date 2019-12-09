/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** box management
*/

#include "my_sokoban.h"

int is_box_pos(int pos, int *list_obj_pos, int size_list)
{
    for (int i = 0; i < size_list; i++) {
        if (pos == list_obj_pos[i])
            return 1;
    }
    return 0;
}

static void move_box(map_t *map, int src, int dest)
{
    for (int i = 0; i < map->nb_box; i++) {
        if (src == map->box_pos[i]) {
            map->box_pos[i] = dest;
            return;
        }
    }
}

int box_check_and_move(map_t *map, int pos, int key)
{
    int dst = get_destination(map, pos, key);
    int have_box_dest = is_box_pos(dst, map->box_pos, map->nb_box);

    if (!have_box_dest && (map->map[dst] == 'O' || map->map[dst] == ' ')) {
        move_box(map, pos, dst);
        if (map->map[dst] == 'O' && eval_game(map))
            return EXIT_WIN;
        else if (check_deadlock(map, dst))
            return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}
