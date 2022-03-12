#include <stdio.h>
#include <stdlib.h>

// Memoria denamica

int main()
{

    /*
        USO DE MALLOC
    */

    int *i;
    i = malloc(sizeof(int)); // malloc(sizeof(int)) devuelve un puntero que apunta a un bloque de memoria del tamaño de un int.

    /*
        si i apunta a NULL se advierte del error.
        que apunte a NULL significa que no se puede realizar la asignacion
    */

    if (i == NULL) { printf("Fatal error"); }
    else
    {
        *i = 5;
        printf("%p : %i \n", &i, *i);
    }

    /*
        USO DE realloc
    */

    // redimenosinar el puntero a 15 bytes y se lo asignamos a un puntero temporal

    int *tpm_ptr = realloc(i, 15);

    if (tpm_ptr == NULL)
    {
        printf("redimension error \n");
    }
    else
    {
        // redimension exitosa. Se asigna al puntero principal
        i = tpm_ptr;
        printf("redimensin succesfull\n");
        printf("%p : %i size : %i \n", &i, *i, (int)sizeof(&i));
    }

    free(i);  // libera el espacio de memoria reservado
    i = NULL; // se recomienda luego de liberar un puntero con free dejarlo a NULL
    printf("%p : %i size : %i \n", &i, *i, (int)sizeof(&i));

    return 0;
}