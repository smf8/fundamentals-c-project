//
// Created by SMF8 on 1/9/2019.
//

#ifndef FUNDAMENTALCPROJECT_FILEIO_H
#define FUNDAMENTALCPROJECT_FILEIO_H

#include "LinkedList.h"

Choice readChoice(char fileName[20]);

int readChoices(char *strings[]);

void load_game_config();

#endif //FUNDAMENTALCPROJECT_FILEIO_H
