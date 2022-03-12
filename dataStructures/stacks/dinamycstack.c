#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *next;
};

struct node *top;

void insert(struct node *, int i);
void view(struct node *);

int main() 
{
    top = NULL;
    int i;

    printf("dato: ");
    scanf("%i",  &i);

    while(i != -1)
    {
        insert(top, i);
        printf("dato: ");
        scanf("%i",  &i);
    }

    view(top);

    return 0;
}

void insert(struct node *top, int i)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));

    if(new == NULL) { printf("algo salio mal"); }

    new->i = i;
    new->next = top;
    top = new;
}

void view(struct node *top)
{
    printf("%i ", top->i); 
}