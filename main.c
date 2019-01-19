#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "FileIO.h"
#include "game.h"
#include <windows.h>
#include <stdbool.h>

int main() {
    printf(BOLDGREEN"\n**** Welcome ****\n" RESET);
    printf("For playing enter " GREEN "[P]" RESET " and for seeing the scoreboard enter" GREEN "[B]" RESET);
    char c;
//    scanf("\n");
    scanf("%c", &c);
    c = tolower(c);
    while(c != 'p' || c != 'b'){
        scanf("%c", &c);
        c = tolower(c);
    }

    gets(username);
    srand((unsigned int) time(NULL));
    play_game();
    return 0;
}