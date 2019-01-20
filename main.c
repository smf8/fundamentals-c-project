#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "FileIO.h"
#include "game.h"
#include "misc.h"
#include <windows.h>
#include <stdbool.h>

int main() {
    printf(BOLDGREEN"\n**** Welcome ****\n" RESET);
    printf("For playing enter " GREEN "[P]" RESET " and for seeing the scoreboard enter" GREEN "[B]\n" RESET);
    char c[10];
    scanf("\n");
    scanf("%s", c);
//    c = tolower(c);
    while(strcmp(c, "p") !=0 && strcmp(c, "b") != 0){
        printf(RED "Invalid Input. please try again\n" RESET);
        scanf("\n");
        scanf("%s", c);
//        c = tolower(c);
    }
    srand((unsigned int) time(NULL));
    if (strcmp("p", c) == 0) {
        printf(CYAN "Enter your username : \n" RESET);
        scanf("\n");
        gets(username);
        play_game();
    }else{

        printf(YELLOW "Choose the element to do the sorting based on : \n" RESET);
        printf("[a] " GREEN " For sorting based on " BLUE "AVERAGE" RESET GREEN " of scores\n" RESET);
        printf("[p] " GREEN " For sorting based on " BLUE "\"PEOPLE\"" RESET GREEN " score\n" RESET);
        printf("[c] " GREEN " For sorting based on " BLUE "\"COURT\"" RESET GREEN " score\n" RESET);
        printf("[t] " GREEN " For sorting based on " BLUE "\"TREASURY\"" RESET GREEN " score\n" RESET);
        printf("[l] " GREEN " For sorting based on " BLUE "\"LEVEL\"\n" RESET);
        scanf("%s", c);
        while(strcmp(c, "a") !=0 && strcmp(c, "p") != 0 &&strcmp(c, "c") !=0 &&strcmp(c, "t") !=0 &&strcmp(c, "l") !=0 ){
            printf(RED "Invalid Input. please try again\n" RESET);
            scanf("\n");
            scanf("%s", c);
//        c = tolower(c);
        }
        read_saves();
        sort_by_element(c[0]);
        printf(RED"==================="RESET CYAN"SCORES" RESET RED "=====================\n"RESET);
        for (int i = 0; i < scoreBoardSize; ++i) {
            if(i == 0){
            printf(RED"||"RESET"                %d" BOLDGREEN " %-10s" RESET "              "RED"||\n"RESET, (i+1), scoreBoard[i].name);
            }else if(i == 1){
                printf(RED"||"RESET"                %d" BOLDCYAN " %-10s" RESET "              "RED"||\n"RESET, (i+1), scoreBoard[i].name);
            }else if(i == 2){
                printf(RED"||"RESET"                %d" BOLDYELLOW " %-10s" RESET "              "RED"||\n"RESET, (i+1), scoreBoard[i].name);
            }else{
                printf(RED"||"RESET"                %d %-10s              "RED"||\n"RESET, (i+1), scoreBoard[i].name);
            }
        }
        printf(RED"==============================================\n"RESET);
    }
    return 0;
}