#include <stdio.h>    
#include <stdlib.h>   // contiene la funcion malloc()

struct node   // representa un nodo con un dato y un puntero al nodo siguiente
{
    int i;
    struct node *next;
};

void insert(struct node **, int);   // funcion para insertar un nodo en la lista
void view(struct node *);           // representar la lista 
void delete(struct node **);        // borrar la lista

int main()
{
    int i;                      // dato a insertar en la lista
    struct node *top = NULL;    // puntero para acceder a los nodos de la lista
                                
    printf("data: ");
    scanf("%i", &i);

    while (i != -1)
    {
        insert(&top, i);
        printf("data: ");
        scanf("%i", &i);
    }

    view(top);
    delete(&top);
    view(top);

    return 0;
}

void insert(struct node **top, int i)  
{
    struct node *new;                                   // crear un nuevo nodo
    new = (struct node *) malloc(sizeof(struct node));  // reservar memoria para ese nodo
    new->i = i;                                         // insertar el dato en su respectivo campo del nodo
    new->next = *top;                                   // el puntero al siguiente elemento pasa a apuntar al elemento anterior 
    *top = new;                                         // almacenamos el nuevo elemento en la ultima posicion de la lista
}                                                       // y el puntero top pasa a apuntar a el nuevo elemento

void view(struct node *top)
{
    if (top == NULL) {printf("lista vacia"); }
    
    while(top != NULL)
    {
        printf("%i -> %p : %p\n", top->i, &(*top->next), &(*top));
        top = top->next;
    }
}

void delete(struct node **top)
{
    struct node *tmp_node;

    while(*top != NULL)
    {
        tmp_node = *top; 
        *top = (*top)->next;  
        free(tmp_node); 
    }
}    