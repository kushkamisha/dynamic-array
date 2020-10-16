//
//  array.c
//  dynamic-arr
//
//  Created by Kushka Misha on 10/15/20.
//  Copyright © 2020 Misha Kushka. All rights reserved.
//

#include "array.h"

struct node
{
    int data;
    struct node* next;
};
typedef struct node node;

node *head = NULL;

void __push(node **head, int data)
{
    node *node = malloc(sizeof(node));
    node->data = data;
    node->next = NULL;

    if (*head == NULL) {
        *head = node;
    } else {
        struct node *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = node;
    }
}

int __pop(node **head)
{
    if (*head == NULL) return 0;

    int value = 0;
    if ((*head)->next == NULL) {
        value = (*head)->data;
        *head = NULL;
        return value;
    }
    node *curr = *head;

    // Go to the penultimate element of array
    while (curr->next->next != NULL) curr = curr->next;

    value = curr->next->data;
    curr->next = NULL;
    return value;
}

void __print(node* head)
{
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

bool __isInArray(node* head, int value) {
    node *curr = head;

    while (curr != NULL) {
        if (curr->data == value) return true;
        curr = curr->next;
    }

    return false;
}

unsigned int __length(node *head) {
    node *curr = head;
    unsigned int length = 0;

    while (curr != NULL) {
        length++;
        curr = curr->next;
    }

    return length;
}

int __get(node *head, int index) {
    node *curr = head;
    int i = 0;

    while (curr != NULL) {
        if (i == index) return curr->data;
        curr = curr->next;
        i++;
    }

    return 0;
}

// Wrappers
void push(int data) { __push(&head, data); }
int pop() { return __pop(&head); }
bool isInArray(int value) { return __isInArray(head, value); }
void print() { __print(head); }
unsigned int length() { return __length(head); }
int get(int index) { return __get(head, index); }

array Array() {
    array this;

    this.push = &push;
    this.pop = &pop;
    this.print = &print;
    this.isInArray = &isInArray;
    this.length = &length;
    this.get = &get;

    return this;
}
