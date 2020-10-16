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

    printf("The length of the array is %d\n", arr.length());

    arr.push(9);
    arr.push(5);
    arr.push(3);

    printf("The length of the array is %d\n", arr.length());

    arr.print();
    
    printf("Is '3' in array? %s\n", arr.isInArray(3) ? "yes" : "no");
    printf("Is '8' in array? %s\n", arr.isInArray(8) ? "yes" : "no");

    printf("Pop: %d\n", arr.pop());

    printf("The length of the array is %d\n", arr.length());
    for (int i = 0; i < arr.length(); i++) {
        printf("%d, ", arr.get(i));
    }
    printf("\n");
    
    printf("Pop: %d\n", arr.pop());
    printf("Pop: %d\n", arr.pop());
    arr.print();

    return 0;
}
