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
    save_user_data(userStats, problemsLeft);
    printf("Saved user data in file\n");
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
        userStats.treasury = lastStats.treasury;
        userStats.people = lastStats.people;
        userStats.court = lastStats.court;
    }
}

void get_user_choice(node c) {
    int choice;
    scanf("%d", &choice);
    if (choice == -1) {
        save_game();
        userQuit = 1;
        return;
    }
    (c->choice).probability -= 1;
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
void load_game() {
    head = NULL;
    read_choices();
    char address[30];
    strcpy(address, "Saves\\");
    strcat(address, username),
            strcat(address, ".bin");
    FILE *filePtr = fopen(address, "rb");
    fread(&userStats, sizeof(point), 1, filePtr);
    int problemsCnt[NOProblems];
    fread(problemsCnt, sizeof(int), (size_t) NOProblems, filePtr);
    for (int i = 0; i < NOProblems; ++i) {
        if (problemsCnt[i] > 0) {
            char fileName[10];
            strcpy(fileName, "c");
            char tmp[12];
            sprintf(tmp, "%d", (i + 1));
            strcat(fileName, tmp);
            strcat(fileName, ".txt");
            Choice c = readChoice(fileName);
            c.id = (i + 1);
            c.probability = problemsCnt[i];
            printf("problem[%d] is : %d\n", (i + 1), c.probability);
            head = add_node(head, c);
            // file c[i] must be added to our linked list
        }
    }
}

int check_user_name() {
    char address[30];
    strcpy(address, "Saves\\");
    strcat(address, username),
            strcat(address, ".bin");

    if (!check_if_file_exist(address)) {
        puts("Username was not found. Starting a new game...\n");
        // username not found starting from scratch
        return 0;
    } else {
        // found start from a saved game
        return 1;
    }
}


void play_game() {
    userQuit = 0;
    if (check_user_name()) {
        // must start from a save;
        printf("You are playing from where you left of. You were at level [%d] of the game\n", userStats.level);

        if (is_game_over()) {
            printf("You have lost the last game you played\nStarting a new game ...\n");
            load_game_config();
            point p;
            p.level = 0;
            update_user_stats(p);
        } else {
            load_game();
            printf("Last stats :\nPeople : %d\nCourt : %d\nTreasury : %d\n", userStats.people, userStats.court,
                   userStats.treasury);
        }
    } else {
        printf("Welcome %s to this fucking game\n", username);
        printf("If you don't know how to play, well unfortunately there is no tutorial but I'll be glad to help you in person.\n");
        // loads setting files in Files\Choices.txt
        load_game_config();
        // initial stats (50,50,50) with level 0; must change in future releases
        point stats;
        stats.level = 0;
        update_user_stats(stats);
    }
    // code for running game for 5 rounds for playing the final game remove below i and it's usages
//    int i = 0;
    while (!is_game_over() && userQuit != 1) {

        if (is_list_empty(head) == -1) {
            // List is Empty:
            printf("List is empty \n");
            load_game_config();
        }

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
//        i++;
//        if (i >= 8) {
//            save_game();
//            break;
//        }
    }
    if (is_game_over()) {
        save_game();
        printf("Game over...\n you lost after [%d] levels", userStats.level);
    }
}

