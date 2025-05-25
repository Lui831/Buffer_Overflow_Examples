/* --------------------------------------------------------------------------------------- */
// example1.c
// Authors: Luiz H. A. Santos and Bruno G. Mauricio
// Date: 17-05-2025
// Description: example of a C program that issues a buffer overflow based on stdio on heap memory
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


/* --------------------------------------------------------------------------------------- */
// Main function

int main() {
    char* input_buffer = (char*)malloc(5);
    char* vulnerable_buffer = input_buffer + 5;
    printf("Enter a string: ");
    gets(input_buffer);
    printf("Input buffer address: %p\n", (void*)input_buffer);
    printf("Vulnerable buffer address: %p\n", (void*)vulnerable_buffer);
    printf("You entered: %s\n", input_buffer);
    printf("Buffer overflow: %s\n", vulnerable_buffer);
    
    // Check if the input buffer contains the magic string
    if (strcmp(vulnerable_buffer, "MAGIC_STRING") == 0) {
        root_function();
    } else {
        common_function();
    }
    
    return 0;
}
