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