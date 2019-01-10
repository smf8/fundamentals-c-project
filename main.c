
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "FileIO.h"
#include "game.h"


int main() {
    printf("Enter username : \n");
    gets(username);
    srand((unsigned int) time(NULL));
    play_game();
    return 0;
}