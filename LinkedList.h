//
// Created by SMF8 on 1/9/2019.
//

#ifndef FUNDAMENTALCPROJECT_LINKEDLIST_H
#define FUNDAMENTALCPROJECT_LINKEDLIST_H

typedef struct LinkedList *node;
node head;
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

node add_node(node head, Choice value);

void show_choice(node head, int id);

void delete_node(node *head, int id);

#endif //FUNDAMENTALCPROJECT_LINKEDLIST_H
