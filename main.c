
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "FileIO.h"



int main() {
    char username[30];
    printf("Enter username : \n");
    gets(username);

    load_game_config();
//    printf(" ---   %s  ---", head->next->next->choice.problem);
    int problems[NOProblems];
    problems[0] = 1;
    problems[1] = 1;
    problems[2] = 0;
    problems[3] = 2;
    problems[4] = 3;
    problems[5] = 0;
    point p;
    strcpy(p.name, username);
    p.court = 70;
    p.people= 20;
    p.treasury = 60;
    p.level = 4;
    save_user_data(p, problems);


    FILE * filePtr = fopen("FILES\\smf.bin", "rb");
    point p2;
    int problem[NOProblems];
    fread(&p2, sizeof(point), 1, filePtr);
    printf("%d - %d - %d\n", p2.people, p2.court, p2.treasury);
    fread(problem, sizeof(int), (size_t) NOProblems, filePtr);
    for (int i = 0; i <6 ; ++i) {
        printf("- %d - ", problem[i]);
    }
    return 0;
}