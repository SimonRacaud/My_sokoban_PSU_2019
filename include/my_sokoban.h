/*
** EPITECH PROJECT, 2019
** my_sokoban_2019
** File description:
** Task02 - Headers of libmy
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#define EXIT_ERROR 84
#define EXIT_SUCCESS 0
#define EXIT_RELOAD 42
#define KEY_SPACE 32

#include "my.h"
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <ncurses.h>

typedef struct stat stat_t;

typedef struct map {
    char *map;
    int max_width;
    int max_height;
    int size;
    int player_pos;
    int *box_pos;
    int nb_box;
    int nb_storage;
    stat_t stat_file;
} map_t;

void clean(map_t *map);
int my_sokoban(char *path_map);

int run(map_t *map);

map_t *read_map(char *path);
int check_map(map_t *map);

#endif
