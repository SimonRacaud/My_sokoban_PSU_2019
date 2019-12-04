/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game loop
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

static int check_deadlock(map_t *map, int pos_box)
{
    int line_box = get_line(map, pos_box);
    int lwidth = get_width_line(map, line_box);
    int have_wall_h = 0;
    int have_wall_v = 0;

    if (map->map[pos_box - 1] == '#' || map->map[pos_box + 1] == '#') {
        have_wall_h = 1;
    } else if (map->map[pos_box - 1] == 'X' || map->map[pos_box + 1] == 'X') {
        have_wall_h = 1;
    }
    if (map->map[pos_box - lwidth] == '#' || map->map[pos_box + lwidth] == '#')
        have_wall_v = 1;
    if (map->map[pos_box - lwidth] == 'X' || map->map[pos_box + lwidth] == 'X')
        have_wall_v = 1;
    if (have_wall_h && have_wall_v)
        return EXIT_END;
    return EXIT_SUCCESS;
}

int box_check_and_move(map_t *map, int pos, int key)
{
    int dst = get_destination(map, pos, key);
    int have_box_dest = is_box_pos(dst, map->box_pos, map->nb_box);

    if (!have_box_dest && (map->map[dst] == 'O' || map->map[dst] == ' ')) {
        move_box(map, pos, dst);
        if (map->map[dst] == 'O' && eval_game(map))
            return EXIT_END;
        else if (check_deadlock(map, dst))
            return EXIT_END;
        return EXIT_SUCCESS;
    }
    return EXIT_ERROR;
}

int eval_game(map_t *map)
{
    for (int i = 0; i < map->nb_box; i++) {
        if (map->map[map->box_pos[i]] == 'O' && i == (map->nb_box - 1)) {
            return EXIT_END;
        } else if (map->map[map->box_pos[i]] != 'O')
            break;
    }
    return EXIT_SUCCESS;
}
