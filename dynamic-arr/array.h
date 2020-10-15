//
//  array.h
//  dynamic-arr
//
//  Created by Kushka Misha on 10/15/20.
//  Copyright © 2020 Misha Kushka. All rights reserved.
//

#ifndef array_h
#define array_h

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node node;

struct array
{
    node *head;
    void (*push)(node**, int);
    int (*pop)(node**);
    void (*print)(node*);
    bool (*isInArray)(node*, int);
    unsigned int (*length)(node*);
};
typedef struct array array;

unsigned int foo(int val);

array Array(void);

void push(node **head, int data);

int pop(node **head);

void print(node *head);

bool isInArray(node *head, int value);

unsigned int length(node *head);

#endif /* array_h */
