
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

void play_game(){
    printf("Welcome %s to this fucking game\n", username);
    printf("If you don't know how to play, well unfortunately there is no tutorial but I'll be glad to help you in person.\n");
    load_game_config();

    // code to generate a random problem
    srand(time(NULL));
    int randomProblemId = (rand() % NOProblems)+1;
    show_choice(head, randomProblemId);
}

int main() {
    printf("Enter username : \n");
    gets(username);
    play_game();
    /*
     char address[30];
    strcpy(address, "Files\\");
    strcat(address, username),
    strcat(address, ".bin");

     if(!check_if_file_exist(address)){
        puts("Username was not found. Do you want to enter your username again?\n");
        puts("\"Y\" for entering username again\n\"N\" for continue with this username");
        char answ;
        scanf("%c", &answ);
        while(answ != 'Y' && answ != 'N') {
            printf("Invalid Input\n");
            puts("\"Y\" for entering username again\n\"N\" for continue with this username");
            scanf("%c", &answ);
        }switch (answ){
                case 'Y':
                    // getting another username
                    puts("Enter new username :");
                    scanf("%s", username);
                    break;
                case 'N':
                    // continiue with this username
//                    save_user_data();
                    break;
            }
    }
*/

//    printf(" ---   %s  ---", head->next->next->choice.problem);
//    int problems[NOProblems];
//    problems[0] = 1;
//    problems[1] = 1;
//    problems[2] = 0;
//    problems[3] = 2;
//    problems[4] = 3;
//    problems[5] = 0;
//    point p;
//    strcpy(p.name, username);
//    p.court = 70;
//    p.people= 20;
//    p.treasury = 60;
//    p.level = 4;
//    save_user_data(p, problems);

//    FILE * filePtr = fopen("FILES\\smf.bin", "rb");
//    point p2;
//    int problem[NOProblems];
//    fread(&p2, sizeof(point), 1, filePtr);
//    printf("%d - %d - %d\n", p2.people, p2.court, p2.treasury);
//    fread(problem, sizeof(int), (size_t) NOProblems, filePtr);
//    for (int i = 0; i <6 ; ++i) {
//        printf("- %d - ", problem[i]);
//    }
    return 0;
}