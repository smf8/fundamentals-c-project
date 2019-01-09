//
// Created by SMF8 on 1/9/2019.
//
#include "FileIO.h"
#include <stdlib.h>
#include <stdio.h>

void load_game_config() {
    // read choices names from CHOICES.txt
    head = NULL;
    char strings[50][20];
    FILE *filePtr = fopen("Files\\CHOICES.txt", "r");
    int index = 0;
    int id = 1;
    while (1) {
        char currentText[20];
        fscanf(filePtr, "%s", currentText);
        strcpy(strings[index], currentText); // name of the choice's file
        Choice c = readChoice(currentText);
        c.id = id;
        id++;
        head = add_node(head, c);
        index++;
        if (feof(filePtr))break;
    }

}

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