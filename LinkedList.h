//
// Created by SMF8 on 1/9/2019.
//

#ifndef FUNDAMENTALCPROJECT_LINKEDLIST_H
#define FUNDAMENTALCPROJECT_LINKEDLIST_H

#include <stdbool.h>

typedef struct LinkedList *node;
node head;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
int NOProblems;
bool isFromSavedGame;
char username[30];
int userQuit;
typedef struct {
    char problem[200];
    char firstChoice[200];
    char secondChoice[200];
    int firstCImpact[3], secondCImpact[3];
    int probability;
    int id;
} Choice;
struct LinkedList {
    Choice choice;
    struct LinkedList *next;
};

typedef struct {
    char name[30];
    int people;
    int court;
    int treasury;
    int level;
} point;
point scoreBoard[200];
int scoreBoardSize;
point userStats;
node add_node(node head, Choice value);
int get_nodes_count(node head);
node show_choice(node head, int id);
node get_node(node head, int order);
node find_node(node head, int id);
int is_list_empty(node head);
void delete_node(node *head, int id);

#endif //FUNDAMENTALCPROJECT_LINKEDLIST_H
