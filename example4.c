/* --------------------------------------------------------------------------------------- */
// example3.c
// Authors: Luiz H. A. Santos and Bruno G. Mauricio
// Date: 17-05-2025
// Description: exemplo de um programa C que simula buffer overflow que, segundo input do usuário, redireciona o fluxo de execução para uma função root_function ou common_function
// Compilation: gcc -o example3 example3.c
// Execution: ./example3
/* --------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------- */
// Bibliotecas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

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

    // Counter
    int i = 0;

    // Allocate a page of executable memory
    void *mem = mmap(NULL, 4096,
                     PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    // Pointer to the input buffer
    char *input_buffer = mem;
    
    // Pointer to the pointer of the function
    void (**ppf)() = mem + 5;

    // Initially stores the comon function
    *ppf = common_function;
    printf("Pointer to the root function address: %p\n", (void *)root_function);
    printf("Pointer to the common function address: %p\n", (void *)common_function);

    printf("Digite a sequencia de caracteres, em bytes, que deseja escrever no buffer: ");

    while(1) {
        
        // Read the input
        scanf("%d", &input_buffer[i]);
        input_buffer[i+1] = '\0';
        // Check if the input is a newline character
        if (input_buffer[i] == '~') {
            input_buffer[i] = '\0';
            break;
        }
        i++;

    }

    printf("Input buffer address: %p\n", (void *)input_buffer);
    printf("Pointer to the function address: %p\n", (void *)ppf);
    printf("You entered: %s\n", input_buffer);

    // Execute the function
    (*ppf)();

    return 0;
}
