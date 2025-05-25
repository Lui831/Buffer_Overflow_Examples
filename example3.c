/* --------------------------------------------------------------------------------------- */
// example3.c
// Authors: Luiz H. A. Santos and Bruno G. Mauricio
// Date: 17-05-2025
// Description: exemplo de um programa C que simula buffer overflow usando strcpy em memória stack
// Compilation: gcc -o example3 example3.c
// Execution: ./example3
/* --------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------- */
// Bibliotecas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* --------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------- */
// Funções auxiliares e structs

void root_function() {
    printf("Root function executed! The system has been breached.\n");
}

void common_function(){
    printf("Common function executed! The system is safe.\n");
}



/* --------------------------------------------------------------------------------------- */
// Função principal

int main() {
    
    char input_buffer[20];
    char* copy_buffer = (char*) malloc(5);
    char* vulnerable_buffer = copy_buffer + 5;

    printf("Enter a string: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    // Remove the newline character from the input
    size_t len = strlen(input_buffer);
    if (len > 0 && input_buffer[len - 1] == '\n') {
        input_buffer[len - 1] = '\0';
    }
    
    // Copy the input to the copy buffer
    strcpy(copy_buffer, input_buffer);

    printf("Input buffer address: %p\n", (void*)input_buffer);
    printf("Copy buffer address: %p\n", (void*)copy_buffer);
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
