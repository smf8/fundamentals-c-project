//
// Created by SMF8 on 1/9/2019.
//
#include "FileIO.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void add_user_save(char username[]) {
    char finalName[20] = "Saves\\";
    strcat(finalName, "saves.txt");
    FILE *filePtr = fopen(finalName, "a");
    fseek(filePtr, 0, SEEK_END);
    fputs(username, filePtr);
    fputs("\n", filePtr);
    fclose(filePtr);
}

void read_saves(){
    FILE * readFilePtr = fopen("Saves\\saves.txt", "r");
    char saves[100][20];
    int index = 0;
    while (1) {
        fscanf(readFilePtr, "%s", saves[index]);
        if (feof(readFilePtr))break;
        strcat(saves[index++], ".bin");
//        printf("%s\n", saves[index-1]);
    }
    scoreBoardSize = index;
    fclose(readFilePtr);
    for (int i = 0; i < index; ++i) {
        char finalName[30] = "Saves\\";
        strcat(finalName, saves[i]);
        FILE * filePtr = fopen(finalName, "r");
        fread(&scoreBoard[i], sizeof(point), 1, filePtr);
        fclose(filePtr);
    }
}

void save_user_data(point stats, int problems[NOProblems]) {
    char finalName[20] = "Saves\\";
    strcat(finalName, stats.name);
    strcat(finalName, ".bin");
    FILE *filePtr = fopen(finalName, "wb");
    fwrite(&stats, sizeof(point), 1, filePtr);
    node t = head;
    int index = 0;
    while (t != NULL) {
//        problems[index] = t->choice.probability;
        index++;
        t = t->next;
    }
    fwrite(problems, sizeof(int), (size_t) NOProblems, filePtr);
    fclose(filePtr);
}

int check_if_file_exist(char fileAddress[30]) {
    FILE *filePtr = fopen(fileAddress, "r");
    if (filePtr == NULL) {
        fclose(filePtr);
        return 0;
    } else {
        fclose(filePtr);
        return 1;
    }
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
//            printf("problem[%d] is : %d\n", (i + 1), c.probability);
            head = add_node(head, c);
            // file c[i] must be added to our linked list
        }
    }
}


// read choices count from CHOICES.txt and save the number in NOProblems
void read_choices() {
    FILE *filePtr = fopen("Files\\CHOICES.txt", "r");
    int index = 0;
    while (1) {
        fscanf(filePtr, "%s");
        index++;
        if (feof(filePtr))break;
    }
    NOProblems = index;
    fclose(filePtr);
}

// Load list of choices from Files\CHOICES.txt and add each one to our Linkedlist
// this function is for times we want to load every setting as default
void load_game_config() {
    head = NULL;
    char strings[50][20];
    FILE *filePtr = fopen("Files\\CHOICES.txt", "r");
    int index = 0;
    int id = 1;
    // reading line by line until reaching the end
    while (1) {
        char currentText[20];
        fscanf(filePtr, "%s", currentText);
        strcpy(strings[index], currentText); // name of the choice's file
        Choice c = readChoice(currentText);
        c.id = id;
        c.probability = 3;
        id++;
        head = add_node(head, c);
        index++;
        if (feof(filePtr))break;
    }
    NOProblems = index;
    fclose(filePtr);
}


// function to read choice data from Files
Choice readChoice(char fileName[20]) {
    FILE *filePtr;
    char finalName[20] = "Files\\";
    strcat(finalName, fileName);
//    puts(finalName);
    filePtr = fopen(finalName, "r");
    if (filePtr == NULL) {
        printf("Choice file not found!\n");
    }
    Choice c;
    fgets(c.problem, 200, filePtr);
    fgets(c.firstChoice, 200, filePtr);
    fscanf(filePtr, "%d\n", &c.firstCImpact[0]);
    fscanf(filePtr, "%d\n", &c.firstCImpact[1]);
    fscanf(filePtr, "%d\n", &c.firstCImpact[2]);
    fgets(c.secondChoice, 200, filePtr);
    c.probability = 3;
    fscanf(filePtr, "%d", &c.secondCImpact[0]);
    fscanf(filePtr, "%d", &c.secondCImpact[1]);
    fscanf(filePtr, "%d", &c.secondCImpact[2]);
    fclose(filePtr);
    return c;
}