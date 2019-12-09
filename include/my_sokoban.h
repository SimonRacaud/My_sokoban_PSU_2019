/*
** EPITECH PROJECT, 2019
** my_sokoban_2019
** File description:
** Task02 - Headers of libmy
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include "my.h"
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <ncurses.h>

static const int EXIT_ERROR = 84;
static const int EXIT_RELOAD = 42;
static const int EXIT_FAIL = 1;
static const int EXIT_WIN = 2;

static const int KEY_SPACE = 32;
static const int K_DOWN = 66;
static const int K_UP = 65;
static const int K_LEFT = 68;
static const int K_RIGHT = 67;

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
void clean_char(map_t *map);
int my_sokoban(char *path_map);

map_t *read_map(char *path);
int check_map(map_t *map);

int run(map_t *map);

int player_check_and_move(map_t *map, int key);

int get_width_line(const map_t *map, const int line);
int get_line(const map_t *map, const int position);
int get_destination(map_t *map, int pos, int key);

int is_box_pos(int pos, int *list_obj_pos, int size_list);
int box_check_and_move(map_t *map, int pos, int key);

int eval_game(map_t *map);
int check_deadlock(map_t *map, int pos_box);

#endif
