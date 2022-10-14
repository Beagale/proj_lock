#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "lock.h"
#include "common.h"

//#define pin_export "/sys/class/gpio/export" // NOTE: probably better way to make this more appliable for other pins, can look into this ..
#define pin_71_direction "/sys/class/gpio/gpio71/direction"
#define pin_71_value "/sys/class/gpio/gpio71/value"


void Lock_init(void)
{
    // NOTE: We're assuming that pin71 has already been exported
    //Common_writeToFile(pin_export, 71);
    printf("export command ran\n");
    Common_writeToFile_char(pin_71_direction, "in");

}

void Lock_unlock(bool correct_pw)
{
    //If entered 12-Digit pin is correct, function will unlock magnetic door lock
    if(correct_pw){
        Common_writeToFile_char(pin_71_value, "1");
    }

}

void Lock_lock()
{ 
    Common_writeToFile_char(pin_71_value, "0");

}
