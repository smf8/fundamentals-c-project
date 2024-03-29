//
// Created by SMF8 on 1/9/2019.
//

#ifndef FUNDAMENTALCPROJECT_FILEIO_H
#define FUNDAMENTALCPROJECT_FILEIO_H

#include <stdio.h>
#include "LinkedList.h"

Choice readChoice(char fileName[20]);
void read_choices();
void save_user_data(point stats, int problems[NOProblems]);
void load_game_config();
void add_user_save(char username[]);
void load_game();
void read_saves();
void save_problem(char *filename, Choice c);
        int check_if_file_exist(char fileAdress[30]);
#endif //FUNDAMENTALCPROJECT_FILEIO_H
