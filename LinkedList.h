//
// Created by SMF8 on 1/9/2019.
//

#ifndef FUNDAMENTALCPROJECT_LINKEDLIST_H
#define FUNDAMENTALCPROJECT_LINKEDLIST_H

typedef struct LinkedList *node;
node head;
int NOProblems;
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

point userStats;
node add_node(node head, Choice value);

node show_choice(node head, int id);
node find_node(node head, int id);
int is_list_empty(node head);
void delete_node(node *head, int id);

#endif //FUNDAMENTALCPROJECT_LINKEDLIST_H
