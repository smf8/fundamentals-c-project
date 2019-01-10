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
        userStats.treasury = lastStats.treasury;
        userStats.people = lastStats.people;
        userStats.court = lastStats.court;
    }
}

void get_user_choice(node c) {
    int choice;
    (c->choice).probability -= 1;
    scanf("%d", &choice);
    while (choice != 1 && choice != 2) {
        printf("Invalid Input\n");
        scanf("%d", &choice);
    }
    if (choice == 1) {
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

void play_game() {
    printf("Welcome %s to this fucking game\n", username);
    printf("If you don't know how to play, well unfortunately there is no tutorial but I'll be glad to help you in person.\n");
    load_game_config();
    point stats;
    stats.level = 0;
    update_user_stats(stats);

    // code to generate a random problem
    while (!is_game_over()) {
        int randomProblemId = (rand() % NOProblems) + 1;
        node selectedNode = show_choice(head, randomProblemId);
        while (selectedNode == NULL) {
            randomProblemId = (rand() % NOProblems) + 1;
            selectedNode = show_choice(head, randomProblemId);
        }
        if (selectedNode != NULL) {
            get_user_choice(selectedNode);
            printf("\n\n----------- User stats -------------\nPeople : %d\nCourt : %d\nTreasury : %d\n Level : %d\n\n id : %d remains %d\n\n",
                   userStats.people, userStats.court, userStats.treasury, userStats.level, selectedNode->choice.id,
                   selectedNode->choice.probability);
        }
    }
}

