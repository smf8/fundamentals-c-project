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

void save_game() {
    int problemsLeft[NOProblems];
//    printf(" is number of NOProblems : %d\n" , NOProblems);
    // code for initializing the problem counts
    for (int i = 0; i < NOProblems; ++i) {
        node currentNode = find_node(head, i + 1);
        if (currentNode != NULL) {
            problemsLeft[i] = currentNode->choice.probability;
        } else {
            problemsLeft[i] = 0;
        };
//        printf("- %d - ", problemsLeft[i]);
    }
    if (!isFromSavedGame) {
        add_user_save(username);
        printf("Updated users list for this username\n");
    }
    save_user_data(userStats, problemsLeft);
    printf("You chose to quit at level [" BOLDBLUE "%d" RESET "]\n", userStats.level);
    printf(BOLDGREEN "************ Your game stats are now saved ************\n" RESET);
}
void update_user_stats(point lastStats) {
    if (lastStats.level == 0) {
        // first Round
        userStats.level = 0;
        userStats.people = 50;
        userStats.court = 50;
        userStats.treasury = 50;
        strcpy(userStats.name, username);
    } else {
        userStats.level += 1;
        userStats.treasury = lastStats.treasury<=0?0:lastStats.treasury>=100?100:userStats.treasury;
        userStats.people = lastStats.people<=0?0:lastStats.people>=100?100:userStats.people;
        userStats.court = lastStats.court<=0?0:lastStats.court>=100?100:userStats.court;
    }
}
void get_user_choice(node c) {
    char  choice[10];
    scanf("\n");
    scanf("%s", choice);
    while (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "s") != 0) {
        printf(BOLDRED "Invalid Input\n" RESET);
        scanf("\n");
        scanf("%s", choice);
    }
    if (strcmp(choice, "s") == 0) {
        printf(RED "Do you want to submit your score for the scoreboard ?\n" RESET "Enter [" GREEN "y" RESET"] for yes and [" GREEN "n" RESET"]  for no\n");
        char ch;
        while(1){
//        system("clear");
            scanf("\n");
            scanf("%c", &ch);
            if (ch == 'n' || ch == 'y'){
                break;
            }else{
                printf(RED "Invalid Input. please try again\n" RESET);
            }
        }
        if (ch == 'y'){
            save_game();
        }
            userQuit = 1;
        return;
    }
    (c->choice).probability -= 1;
    if (strcmp(choice, "1") == 0) {
        userStats.people += c->choice.firstCImpact[0];
        userStats.court += c->choice.firstCImpact[1];
        userStats.treasury += c->choice.firstCImpact[2];
        userStats.level++;
    } else {
        userStats.people += c->choice.secondCImpact[0];
        userStats.court += c->choice.secondCImpact[1];
        userStats.treasury += c->choice.secondCImpact[2];
        userStats.level++;
    }
    if (c->choice.probability == 0) {
//        printf("****** Deleted node with ID : %d ******", c->choice.id);
        delete_node(&head, c->choice.id);
    }
}

int is_game_over() {
    if (userStats.treasury <= 0 || userStats.court <= 0 || userStats.people <= 0) {
        return 1;
    }
    if (((userStats.people + userStats.court + userStats.treasury) / 3) < 10) {
        return 1;
    }
    return 0;
}
void reset_game(){
    userStats.treasury = 50;
    userStats.people = 50;
    userStats.level = 0;
    userStats.court = 50;
}

int check_user_name() {
    char address[30];
    strcpy(address, "Saves\\");
    strcat(address, username),
            strcat(address, ".bin");

    if (!check_if_file_exist(address)) {
        puts(RED "USERNAME WAS NOT FOUND\nStarting a new game...\n" RESET);
        // username not found starting from scratch
        return 0;
    } else {
        // found start from a saved game
        return 1;
    }
}

void print_progress(){
    int ppl, crt, trsry;
    ppl = userStats.people / 5;
    crt = userStats.court  /5;
    trsry = userStats.treasury /5;
    if (userStats.people <= 20)
        printf(BOLDRED);
    else if (userStats.people >= 70)
        printf(BOLDGREEN);
    else
        printf(BOLDYELLOW);
    printf("[");
    for (int i = 0; i < 20 ; ++i) {
        i<ppl?printf("#"):printf("-");
    }
    printf("]" RESET " People : [" BOLDBLACK "%d" RESET "]\n", userStats.people<=0?0:userStats.people>=100?100:userStats.people);

    if (userStats.court <= 20)
        printf(BOLDRED);
    else if (userStats.court >= 70)
        printf(BOLDGREEN);
    else
        printf(BOLDYELLOW);
    printf("[");
    for (int i = 0; i < 20 ; ++i) {
        i<crt?printf("#"):printf("-");
    }
    printf("]" RESET " Court : [" BOLDBLACK "%d" RESET "]\n", userStats.court<=0?0:userStats.court>=100?100:userStats.court);
    if (userStats.treasury <= 20)
        printf(BOLDRED);
    else if (userStats.treasury >= 70)
        printf(BOLDGREEN);
    else
        printf(BOLDYELLOW);
    printf("[");
    for (int i = 0; i < 20 ; ++i) {
        i<trsry?printf("#"):printf("-");
    }
    printf("]" RESET " Treasury : [" BOLDBLACK "%d" RESET "]\n", userStats.treasury<=0?0:userStats.treasury>=100?100:userStats.treasury);
}

void play_game() {
    userQuit = 0;
    // check if username file exists
    if (check_user_name()) {

        isFromSavedGame = true;
        // must start from a save;
        printf("You have a saved game with[" BOLDGREEN "%s" RESET "] username\n\nYou can load your last game\n\nRespond by entering either [y] or [n]\n", username);
            char ch;
        while(1){
//        system("clear");
            scanf("\n");
            scanf("%c", &ch);
            if (ch == 'n' || ch == 'y'){
                break;
            }else{
                printf(RED "Invalid Input. please try again\n" RESET);
            }
        }
            load_game();
        if (ch == 'n'){
            load_game_config();
            point p;
            p.level = 0;
            update_user_stats(p);
            printf(BOLDGREEN "**You chose to start a new game from scratch. keep in mind that your last saved game is not destroyed until it is overwritten by a new save.\n" RESET);
        }else {
            if (is_game_over()) {
                // one of parameters is below 0 or average is below 10
                // resetting everything
                printf("You have " RED "LOST" RESET " the last game you played\nStarting a new game ...\n");
                load_game_config();
                point p;
                p.level = 0;
                update_user_stats(p);
            } else {
                print_progress();
//            printf("Last stats :\nPeople : %d\nCourt : %d\nTreasury : %d\n", userStats.people, userStats.court,
//                   userStats.treasury);
            }
        }
    } else {
        printf("Welcome " GREEN "%s" RESET " to this fucking game\n", username);
//        printf("If you don't know how to play, well unfortunately there is no tutorial but I'll be glad to help you in person.\n");
        // loads setting files in Files\Choices.txt
        load_game_config();
        // initial stats (50,50,50) with level 0; must change in future releases
        point stats;
        stats.level = 0;
        update_user_stats(stats);
//        int k = get_nodes_count(head);
//        printf("%d\n" ,k);
//        return;
    }
    // code for running game for 5 rounds for playing the final game remove below i and it's usages
//    int i = 0;
    while (!is_game_over() && userQuit != 1) {
        if (is_list_empty(head) == -1) {
            // List is Empty reloading problems from Files
//            printf("List became empty... reloading it ....................................................\n");
            load_game_config();
        }


        // generating random numbers until reaching a valid Id among list's nodes
//        printf("Nodes count : %d \n", get_nodes_count(head));
        int div = get_nodes_count(head);
        if (div == 0){
            div = 1;
        }
//        print_list();
        int randomProblemId = (rand() % div) + 1;
//        node selectedNode = show_choice(head, randomProblemId);

        node selectedNode = get_node(head, randomProblemId);
            printf("*****************************************************************************************************\n");
        if (selectedNode != NULL) {
            get_user_choice(selectedNode);
//            printf("\n\n----------- User stats -------------\nPeople : %d\nCourt : %d\nTreasury : %d\n Level : %d\n\n id : %d remains %d\n\n",
//                   userStats.people, userStats.court, userStats.treasury, userStats.level, selectedNode->choice.id,
//                   selectedNode->choice.probability);
            print_progress();
        }
    }
    // check if game is over for user
    if (is_game_over()) {
//        save_game();
        printf("*************************************************" BOLDRED "GAME OVER" RESET "*************************************************\n");
        printf("You lost after [" BOLDGREEN "%d" RESET "] levels\n", userStats.level);
        printf(RED "Do you want to submit your score for the scoreboard ?\n" RESET "Enter [" GREEN "y" RESET"] for yes and [" GREEN "n" RESET"]  for no\n");
        char ch;
        while(1){
//        system("clear");
            scanf("\n");
            scanf("%c", &ch);
            if (ch == 'n' || ch == 'y'){
                break;
            }else{
                printf(RED "Invalid Input. please try again\n" RESET);
            }
        }
        if (ch == 'y'){
            save_game();
            userQuit = 1;
        }
    }
}

