/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** file manager
*/

#include "my_sokoban.h"

static void init_map(map_t *map)
{
    map->size = (map->stat_file.st_size + 1);
    map->player_pos = -1;
    map->box_pos = NULL;
    map->nb_box = 0;
}

static int check_char(char c)
{
    if (c == ' ' || c == '\n' || c == '#' || c == 'X' || c == 'O' || c == 'P')
        return EXIT_SUCCESS;
    return EXIT_ERROR;
}

static int get_box(map_t *map)
{
    int idx_box = 0;

    map->map[map->size] = '\0';
    map->box_pos = malloc(sizeof(int) * map->nb_box);
    if (!map->box_pos)
        return EXIT_ERROR;
    for (int i = 0; map->map[i] != '\0'; i++) {
        if (map->map[i] == 'X') {
            map->box_pos[idx_box++] = i;
        }
    }
    return EXIT_SUCCESS;
}

int check_map(map_t *map)
{
    init_map(map);
    if (map->size == 1)
        return EXIT_ERROR;
    for (int i = 0; map->map[i] != '\0'; i++) {
         if (map->map[i] == 'P' && map->player_pos == -1) {
            map->player_pos = i;
        } else if (map->map[i] == 'P') {
            return EXIT_ERROR;
        }
        if (map->map[i] == 'X') {
            map->nb_box++;
        } else if (map->map[i] == 'O') {
            map->nb_storage++;
        }
        if (check_char(map->map[i]) == EXIT_ERROR)
            return EXIT_ERROR;
     }
     if (map->nb_box != map->nb_storage || get_box(map) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

map_t *read_map(char *path)
{
    map_t *map = malloc(sizeof(map_t));
    int ret = stat(path, &map->stat_file);
    int fd = open(path, O_RDONLY);

    if (fd == -1 || ret != 0) {
        my_putstr_error("ERROR: open file\n");
        return NULL;
    }
    if (!(map->map = malloc(sizeof(char) * (map->stat_file.st_size + 1))))
        return NULL;
    ret = read(fd, map->map, (map->stat_file.st_size + 1));
    close(fd);
    if (ret == -1) {
        my_putstr_error("ERROR: read file\n");
        return NULL;
    } else if (check_map(map) == EXIT_ERROR) {
        my_putstr_error("ERROR: check map : invalid map\n");
        return NULL;
    }
    return map;
}
