/* --------------------------------------------------------------------------------------- */
// example2.c
// Authors: Luiz H. A. Santos and Bruno G. Mauricio
// Date: 17-05-2025
// Description: example of a C program that issues a buffer overflow based on stdio on stack memory
// Compilation: gcc -o example1 example1.c]
// Execution: ./example1
/* --------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------- */
// Libraries

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* --------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------- */
// Auxiliary functions and structs

void root_function() {
    printf("Root function executed! The system has been breached.\n");
}

void common_function(){
    printf("Common function executed! The system is safe.\n");
}

typedef struct {
    char input_buffer[5];
    char vulnerable_buffer[5];
} vulnerable_struct;


/* --------------------------------------------------------------------------------------- */
// Main function

int main() {
    vulnerable_struct vs;
    printf("Enter a string: ");
    gets(vs.input_buffer);
    printf("Input buffer address: %p\n", (void*) vs.input_buffer);
    printf("Vulnerable buffer address: %p\n", (void*) vs.vulnerable_buffer);
    printf("You entered: %s\n", vs.input_buffer);
    printf("Buffer overflow: %s\n", vs.vulnerable_buffer);
    
    // Check if the input buffer contains the magic string
    if (strcmp(vs.vulnerable_buffer, "MAGIC_STRING") == 0) {
        root_function();
    } else {
        common_function();
    }
    
    return 0;
}
