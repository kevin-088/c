#include <stdio.h>

struct element {
    int x;
    int y;
};

struct stack {
    struct element *elements;
    int count;
    int top;
};

int make_stack(struct stack *, int);
int push(struct stack *, struct element);
int pop(struct stack *, struct element *);

int main() {

    struct stack mystack;

    make_stack(&mystack, 4);

    struct element e1;
    struct element e2;
    struct element e3;
    struct element e4;

    e1.x = 1;
    e1.y = 2;

    e2.x = 3;
    e2.y = 4;

    e3.x = 5;
    e3.y = 6;

    e4.x = 7;
    e4.y = 8;

    push(&mystack, e1);
    push(&mystack, e2);
    push(&mystack, e3);
    push(&mystack, e4);

    for(int i = 0; i < 4; i++) {
        printf("objeto %i : x: %i y: %i \n", i, mystack.elements[i].x, mystack.elements[i].y);
    }

    return 0;
}

int make_stack(struct stack *p, int num_elements) {

    if (num_elements < 1) { return -1; }

    struct element array_elements[num_elements];

    p->elements = array_elements;
    p->count = 0;
    p->top = num_elements - 1;

    return 1;
}

int push(struct stack *p, struct element element) {

    p->elements[p->count] = element;
    p->count++;

    return 1;
}