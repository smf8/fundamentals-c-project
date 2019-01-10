//
// Created by SMF8 on 1/10/2019.
//

#include "game.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "FileIO.h"


void update_user_stats(point lastStats){
    if (lastStats.level == 0){
        // first Round
        userStats.level = 0;
        userStats.people = 50;
        userStats.court = 50;
        userStats.treasury = 50;
        strcpy(userStats.name, username);
    }else{
        userStats.level += 1;
        userStats.treasury = lastStats.treasury;
        userStats.people = lastStats.people;
        userStats.court = lastStats.court;
    }
}
void get_user_choice(){

}
void play_game(){
    printf("Welcome %s to this fucking game\n", username);
    printf("If you don't know how to play, well unfortunately there is no tutorial but I'll be glad to help you in person.\n");
    load_game_config();
    // code to generate a random problem
    srand(time(NULL));
    int randomProblemId = (rand() % NOProblems)+1;
    show_choice(head, randomProblemId);

}

