//
//  main.c
//  dynamic-arr
//
//  Created by Kushka Misha on 10/10/20.
//  Copyright © 2020 Misha Kushka. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct array
{
    int data;
    struct array* next;
    
    int (*someFunction)(void);
};
typedef struct array array;

void push(array **head, int data)
{
    array *node = malloc(sizeof(array));
    node->data = data;
    node->next = NULL;

    if (*head == NULL) {
        *head = node;
    } else {
        struct array *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = node;
    }
}

int pop(array **head)
{
    if (*head == NULL) return 0;

    int value = 0;
    if ((*head)->next == NULL) {
        value = (*head)->data;
        *head = NULL;
        return value;
    }
    array *curr = *head;

    // Do to the penultimate element of array
    while (curr->next->next != NULL) curr = curr->next;

    value = curr->next->data;
    curr->next = NULL;
    return value;
}

void print(array *head)
{
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

bool isInArray(array *head, int value) {
    array *curr = head;

    while (curr != NULL) {
        if (curr->data == value) return true;
        curr = curr->next;
    }

    return false;
}

unsigned int length(array *head) {
    array *curr = head;
    unsigned int length = 0;

    while (curr != NULL) {
        length++;
        curr = curr->next;
    }

    return length;
}

int main(int argc, const char * argv[]) {

    array *head = NULL;

    printf("The length of the array is %d\n", length(head));

    push(&head, 4);
    push(&head, 9);
    push(&head, 3);

    printf("The length of the array is %d\n", length(head));

    print(head);
    printf("Is '3' in array? %s\n", isInArray(head, 3) ? "yes" : "no");

    printf("Pop: %d\n", pop(&head));
    print(head);
    printf("Pop: %d\n", pop(&head));
    printf("Pop: %d\n", pop(&head));
    print(head);

    return 0;
}

//#include <stdio.h>
//
//struct array {
//    int (*someFunction)(void);
//};
//
//typedef struct array array;
//
//int foo() {
//    return 1;
//}
//
//array Array() {
//    array this;
//    this.someFunction = &foo;
//    return this;
//}
//
//int main()
//{
//    array arr = Array();
//    printf("Print hello: %d\n", arr.someFunction());
//
//    return 0;
//}
