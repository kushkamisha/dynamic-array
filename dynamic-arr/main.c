//
//  main.c
//  dynamic-arr
//
//  Created by Kushka Misha on 10/10/20.
//  Copyright © 2020 Misha Kushka. All rights reserved.
//
#include "array.h"

int main(int argc, const char * argv[]) {
    
    array arr = Array();
    node *head = NULL;

    printf("The length of the array is %d\n", arr.length(head));

    arr.push(&head, 9);
    arr.push(&head, 5);
    arr.push(&head, 3);

    printf("The length of the array is %d\n", arr.length(head));

    arr.print(head);
    printf("Is '3' in array? %s\n", arr.isInArray(head, 3) ? "yes" : "no");

    printf("Pop: %d\n", arr.pop(&head));
    arr.print(head);
    printf("Pop: %d\n", arr.pop(&head));
    printf("Pop: %d\n", arr.pop(&head));
    arr.print(head);

    return 0;
}
