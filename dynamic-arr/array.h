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
    void (*push)(int);
    int (*pop)(void);
    void (*print)(void);
    bool (*isInArray)(int);
    unsigned int (*length)(void);
};
typedef struct array array;

array Array(void);

void push(int);
int pop(void);
void print(void);
bool isInArray(int);
unsigned int length(void);

#endif /* array_h */
