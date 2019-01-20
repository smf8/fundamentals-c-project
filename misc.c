//
// Created by SMF8 on 1/20/2019.
//
#include "misc.h"

#include "game.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "FileIO.h"

void sort_by_element(char element) {
    switch (element) {
        case 'v':
            // sort by people score
            for (int c = 0; c < (scoreBoardSize - 1); c++) {
                int position = c;

                for (int d = c + 1; d < scoreBoardSize; d++) {
                    if (scoreBoard[d].people > scoreBoard[position].people)
                        position = d;
                    else if (scoreBoard[d].people== scoreBoard[position].people){
                        if (scoreBoard[d].court > scoreBoard[position].court){
                            position = d;
                        }else if (scoreBoard[d].court == scoreBoard[position].court){
                            if (scoreBoard[d].treasury > scoreBoard[position].treasury)
                                position = d;
                        }
                    }
                }
                // swap current element with maximum among others
                if (position != c) {
                    swap_element(&scoreBoard[c], &scoreBoard[position]);
                }
            }
            break;
            break;
        case 'a':
            for (int c = 0; c < (scoreBoardSize - 1); c++) {
                int position = c;

                for (int d = c + 1; d < scoreBoardSize; d++) {
                    double currentAverage, fixedAverage;
                    fixedAverage = (double) (scoreBoard[position].people + scoreBoard[position].court +
                                             scoreBoard[position].treasury) / 3;
                    currentAverage = (double) (scoreBoard[d].people + scoreBoard[d].court + scoreBoard[d].treasury) / 3;
                    if (currentAverage > fixedAverage)
                        position = d;
                }
                // swap current element with maximum among others
                if (position != c) {
                    swap_element(&scoreBoard[c], &scoreBoard[position]);
                }
            }
            break;
        case 'p':
            // sort by people score
            for (int c = 0; c < (scoreBoardSize - 1); c++) {
                int position = c;

                for (int d = c + 1; d < scoreBoardSize; d++) {
                    if (scoreBoard[d].people > scoreBoard[position].people)
                        position = d;
                }
                // swap current element with maximum among others
                if (position != c) {
                    swap_element(&scoreBoard[c], &scoreBoard[position]);
                }
            }
            break;
        case 'c':

            for (int c = 0; c < (scoreBoardSize - 1); c++) {
                int position = c;

                for (int d = c + 1; d < scoreBoardSize; d++) {
                    if (scoreBoard[d].court > scoreBoard[position].court)
                        position = d;
                }
                // swap current element with maximum among others
                if (position != c) {
                    swap_element(&scoreBoard[c], &scoreBoard[position]);
                }
            }
            break;
        case 't':

            for (int c = 0; c < (scoreBoardSize - 1); c++) {
                int position = c;

                for (int d = c + 1; d < scoreBoardSize; d++) {
                    if (scoreBoard[d].treasury> scoreBoard[position].treasury)
                        position = d;
                }
                // swap current element with maximum among others
                if (position != c) {
                    swap_element(&scoreBoard[c], &scoreBoard[position]);
                }
            }
            break;
        case 'l':

            for (int c = 0; c < (scoreBoardSize - 1); c++) {
                int position = c;

                for (int d = c + 1; d < scoreBoardSize; d++) {
                    if (scoreBoard[d].level> scoreBoard[position].level)
                        position = d;
                }
                // swap current element with maximum among others
                if (position != c) {
                    swap_element(&scoreBoard[c], &scoreBoard[position]);
                }
            }
            break;

    }
}

void swap_element(point *p1, point *p2) {
    point tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void add_problem(){
    Choice c;
    printf(BLUE"Please enter problems description : \n" RESET);
    scanf("\n");
    gets(c.problem);
    printf(BLUE"Please enter first choice's detail : \n"RESET);
    scanf("\n");
    gets(c.firstChoice);
    printf(BLUE"Enter Impact of the \"FIRST CHOICE\"on ["RESET GREEN "PEOPLE" RESET BLUE"] [" GREEN "COURT" RESET BLUE"] [" GREEN "TREASURY" RESET BLUE"] respectively.\n"RESET);
    scanf("%d %d %d", &c.firstCImpact[0],&c.firstCImpact[1],&c.firstCImpact[2]);
    printf(BLUE"Please enter second choice's detail : \n"RESET);
    scanf("\n");
    gets(c.secondChoice);
    printf(BLUE"Enter Impact of the \"SECOND CHOICE\"on ["RESET GREEN "PEOPLE" RESET BLUE"] [" GREEN "COURT" RESET BLUE"] [" GREEN "TREASURY" RESET BLUE"] respectively.\n"RESET);
    scanf("%d %d %d", &c.secondCImpact[0],&c.secondCImpact[1],&c.secondCImpact[2]);
    char filename[20] = "c";
    read_choices();
    char num[2];
    sprintf(num, "%d", (NOProblems)+1);
    strcat(filename, num);
    strcat(filename, ".txt");
    save_problem(filename, c);
}