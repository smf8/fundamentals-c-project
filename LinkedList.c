//
// Created by SMF8 on 1/9/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


node createNode() {
    node temp;
    temp = (node) malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    return temp;
}

node add_node(node head, Choice value) {
    node temp_node = createNode();
    // initialize the node
    strcpy(temp_node->choice.firstChoice, value.firstChoice);
    strcpy(temp_node->choice.problem, value.problem);
    strcpy(temp_node->choice.secondChoice, value.secondChoice);
    temp_node->choice.probability = value.probability;
    temp_node->choice.id = value.id;
    temp_node->choice.firstCImpact[0] = value.firstCImpact[0];
    temp_node->choice.firstCImpact[1] = value.firstCImpact[1];
    temp_node->choice.firstCImpact[2] = value.firstCImpact[2];
    temp_node->choice.secondCImpact[0] = value.secondCImpact[0];
    temp_node->choice.secondCImpact[1] = value.secondCImpact[1];
    temp_node->choice.secondCImpact[2] = value.secondCImpact[2];
    // end of initialization

    if (head == NULL) {
        head = temp_node;
    } else {
        node t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = temp_node;
    }
    return head;
}
node find_node(node head, int id){
    node tmp = head;
    while (tmp->next != NULL && tmp->choice.id != id) {
        tmp = tmp->next;
    }
    if (tmp->choice.id != id) {
        return NULL;
    }
    return tmp;
}
node show_choice(node head, int id) {
    node tmp = head;
    while (tmp->next != NULL && tmp->choice.id != id) {
        tmp = tmp->next;
    }
    if (tmp->choice.id != id) {
        return NULL;
    }
//    printf("---[%d]---\n", tmp->choice.probability);
    puts(tmp->choice.problem);
    printf("Please Choose what to do : \n");
    printf("1- %s", tmp->choice.firstChoice);
    printf("2- %s", tmp->choice.secondChoice);
    return tmp;
}

void delete_node(node *head, int id) {
    node t, q = *head;
    t = q->next;
    if (q->choice.id == id) {
        free(*head);
        *head = t;
        return;
    }
    while (t->choice.id != id || t == NULL) {
        q = t;
        t = t->next;
    }
    q->next = t->next;
    free(t);
}