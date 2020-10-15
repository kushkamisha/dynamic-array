//
//  array.c
//  dynamic-arr
//
//  Created by Kushka Misha on 10/15/20.
//  Copyright © 2020 Misha Kushka. All rights reserved.
//

#include "array.h"

void push(node **head, int data)
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

int pop(node **head)
{
    if (*head == NULL) return 0;

    int value = 0;
    if ((*head)->next == NULL) {
        value = (*head)->data;
        *head = NULL;
        return value;
    }
    node *curr = *head;

    // Do to the penultimate element of array
    while (curr->next->next != NULL) curr = curr->next;

    value = curr->next->data;
    curr->next = NULL;
    return value;
}

void print(node *head)
{
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

bool isInArray(node *head, int value) {
    node *curr = head;

    while (curr != NULL) {
        if (curr->data == value) return true;
        curr = curr->next;
    }

    return false;
}

unsigned int length(node *head) {
    node *curr = head;
    unsigned int length = 0;

    while (curr != NULL) {
        length++;
        curr = curr->next;
    }

    return length;
}

unsigned int foo(int val) {
    return val;
}

array Array() {
    array this;
//    node *head = NULL;
    this.push = &push;
    this.pop = &pop;
    this.print = &print;
    this.isInArray = &isInArray;
    this.length = &length;
    return this;
}
