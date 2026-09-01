#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef TEST
#define main main_exclude
#endif



int main(void)
{
    // I left this in here because the instructions mentioned only to ADD to the file, and it is not hurting anybody.
    char *greeting = get_greeting("World");
    if (greeting) {
        printf("%s\n", greeting);
        free(greeting); // Free the allocated memory for the greeting
    } else {
        printf("Failed to create greeting.\n");
    }

    //char *leaked = malloc(64); // Memory leak for task 4
    
    //volatile int *ptr = NULL; // NULL pointer used to instigate error
    //printf("%d\n", *ptr);  // Dereferencing a NULL pointer to initiate an error condition


    return 0;
}