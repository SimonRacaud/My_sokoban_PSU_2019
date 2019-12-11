/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_sokoban.h"

map_t *make_map_from_string(char *str);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_sokoban, t01)
{
    map_t *map;
    char *board = "#####\n#XOP#\n#####\n";

    map = make_map_from_string(board);
    cr_assert_eq(map->nb_box, 1);
    cr_assert_eq(map->nb_storage, 1);
    cr_assert_eq(map->player_pos, 9);
    clean(map);
}

Test(my_sokoban, t02)
{
    map_t *map;

    map = read_map("tests/map01");
    cr_assert_eq(map->size, 91);
    cr_assert_eq(map->nb_storage, 2);
    cr_assert_eq(map->player_pos, 41);
    cr_assert_eq(map->nb_box, 2);
    cr_assert_eq(map->box_pos[0], 42);
    cr_assert_eq(map->box_pos[1], 68);
    clean(map);
}

Test(my_sokoban, t03)
{
    map_t *map;
    int ret;

    map = read_map("tests/map09");
    ret = player_check_and_move(map, K_RIGHT);
    cr_assert_eq(ret, EXIT_WIN);
    clean(map);
}

Test(my_sokoban, t04)
{
    map_t *map;
    int player_pos;

    map = read_map("tests/map01");
    player_pos = map->player_pos;
    player_check_and_move(map, K_RIGHT);
    cr_assert_eq(map->player_pos, player_pos + 1);
    clean(map);
}

Test(my_sokoban, t05)
{
    map_t *map;
    int player_pos;

    map = read_map("tests/map01");
    player_pos = map->player_pos;
    player_check_and_move(map, K_LEFT);
    cr_assert_eq(map->player_pos, player_pos - 1);
    clean(map);
}

Test(my_sokoban, t06, .init = redirect_all_stdout)
{
    map_t *map;

    map = read_map("tests/map02_err_box1");
    cr_assert_stderr_eq_str("ERROR: check map : invalid map\n");
    free(map);
}

Test(my_sokoban, t07, .init = redirect_all_stdout)
{
    map_t *map;

    map = read_map("tests/map03_err_box2");
    cr_assert_stderr_eq_str("ERROR: check map : invalid map\n");
    free(map);
}

Test(my_sokoban, t08, .init = redirect_all_stdout)
{
    map_t *map;

    map = read_map("tests/map04_err_char");
    cr_assert_stderr_eq_str("ERROR: check map : invalid map\n");
    free(map);
}

Test(my_sokoban, t09, .init = redirect_all_stdout)
{
    map_t *map;

    map = read_map("tests/map05_err_empty");
    cr_assert_stderr_eq_str("ERROR: check map : invalid map\n");
    free(map);
}

Test(my_sokoban, t10, .init = redirect_all_stdout)
{
    map_t *map;

    map = read_map("tests/map06_err_player");
    cr_assert_stderr_eq_str("ERROR: check map : invalid map\n");
    free(map);
}

Test(my_sokoban, t11, .init = redirect_all_stdout)
{
    map_t *map;

    map = read_map("undefined");
    cr_assert_stderr_eq_str("ERROR: open file\n");
    free(map);
}

Test(my_sokoban, t12, .init = redirect_all_stdout)
{
    map_t *map;

    map = read_map("tests/map10_err_player2");
    cr_assert_stderr_eq_str("ERROR: check map : invalid map\n");
    free(map);
}

Test(my_sokoban, t13)
{
    map_t *map;
    int ret;

    map = read_map("tests/map01");
    ret = player_check_and_move(map, K_UP);
    cr_assert_eq(ret, EXIT_SUCCESS);
    clean(map);
}

Test(my_sokoban, t14)
{
    map_t *map;
    int ret;

    map = read_map("tests/map01");
    ret = get_destination(map, 85, K_DOWN);
    cr_assert_eq(ret, -1);
    clean(map);
}

Test(my_sokoban, t15)
{
    map_t *map;
    int ret;

    map = read_map("tests/map01");
    ret = player_check_and_move(map, 0);
    cr_assert_eq(ret, EXIT_SUCCESS);
    clean(map);
}
