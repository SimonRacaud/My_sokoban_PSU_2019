/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** Main Menu
*/

#include "my_sokoban.h"

static const char *MENU_TITLE[6] =
{
".___  ___.      ___       __  .__   __."\
"    .___  ___.  _______ .__   __.  __    __\n",
"|   \\/   |     /   \\     |  | |  \\ |  |    |   \\/   | |   ____||  \\"\
" |  | |  |  |  |\n",
"|  \\  /  |    /  ^  \\    |  | |   \\|  |    |  \\  /  | |  |__   |   \\|"\
"  | |  |  |  |\n",
"|  |\\/|  |   /  /_\\  \\   |  | |  . `  |    |  |\\/|  | |   __|  |  . `"\
"  | |  |  |  |\n",
"|  |  |  |  /  _____  \\  |  | |  |\\   |    |  |  |  | |  |____ |  |\\"\
"   | |  `--'  |\n",
"|__|  |__| /__/     \\__\\ |__| |__| \\__|    |__|  |__| |_______||__| \\"\
"__|  \\______/\n"
};
static const char *MENU_SUBTL = "my sokoban 2019 : RACAUD Simon";
static const char *MENU_CHOICES[6] =
{
    "The Labyrinth",
    "Small room",
    "Medium rect",
    "Medium Map",
    "Mini Map",
    "QUIT"
};
extern const int MAX_MAP;

static void display_menu(int selected_row)
{
    int len_title = my_strlen(MENU_TITLE[0]);
    int len_subtitle = my_strlen(MENU_SUBTL);
    int base_posx = -5;

    clear();
    for (int i = 0; i < 6; i++)
        mvprintw(8 + i, COLS / 2 - len_title / 2, MENU_TITLE[i]);
    mvprintw(15, COLS / 2 - len_subtitle / 2, MENU_SUBTL);
    for (int i = 0; i <= MAX_MAP + 1; i++) {
        if (i == selected_row) {
            attron(A_BOLD);
            mvprintw(20 + (i * 3), base_posx + COLS / 2 - 10, ">", i);
        }
        mvprintw(20 + (i * 3), base_posx + COLS / 2 - 6, "[%d] - ", i);
        mvprintw(20 + (i * 3), base_posx + COLS / 2, MENU_CHOICES[i]);
        if (i == selected_row)
            attroff(A_BOLD);
    }
    printw("\n");
    refresh();
}

static int get_user_input(int *enter, int *selected_row, int max_row)
{
    int in = getch();

    if (in == K_DOWN) {
        (*selected_row)++;
        if (*selected_row > max_row)
            *selected_row = 0;
        return EXITSUCCESS;
    } else if (in == K_UP) {
        (*selected_row)--;
        if (*selected_row < 0)
            *selected_row = max_row;
        return EXITSUCCESS;
    }
    if (in == KEY_SPACE)
        return EXIT;
    else if (in == K_ENTER)
        *enter = !(*enter);
    return EXIT_SUCCESS;
}

int main_menu(void)
{
    int selected_row = 0;
    int enter = 0;
    int max_row = MAX_MAP + 1;

    initscr();
    if (my_init_color() == EXIT_ERROR)
        enter = 1;
    while (!enter) {
        display_menu(selected_row);
        if (get_user_input(&enter, &selected_row, max_row) == EXIT) {
            endwin();
            return EXIT;
        }
    }
    endwin();
    if (selected_row == max_row)
        return EXIT;
    return selected_row;
}
