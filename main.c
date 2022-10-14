// main.c file made to test lock functionality
// *NOT NECESSARILY GOING TO BE THE ACTUAL main.c file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lock.h"
#include "common.h"


int main()
{
    printf("TESTING LOCK FUNCTIONALITY\n");
   
    Lock_init();
    printf("Lockinit function ran\n");

    printf("TESTING Lock_lock function\n");
    Lock_lock();
    printf("Lock_lock function ran\n");

    return 0;
}