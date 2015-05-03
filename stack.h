#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>



typedef struct list
{

    int data;
    struct list *next;

} LIST;

typedef struct stack
{

    LIST *head;

} STACK;

// Returns a pointer to a new stack element
LIST *newListElem(int i)
{

    LIST *t=malloc(sizeof(LIST));
    t->next=NULL;
    t->data=i;
    return t;
}

// Returns a pointer to a newly created stack
STACK *newStack()
{

    STACK *s=malloc(sizeof(STACK));
    s->head=NULL;

    return s;
}

// Returns  1 if stack has no elements , 0 if not
int isEmpty(STACK *s)
{

    if(s->head == NULL)
        return 1;
    else
        return 0;

}

// Puts a new element in the stack
void Push(STACK *s,int i)
{

    LIST *elem=newListElem(i);

    elem->next=s->head;
    s->head=elem;

    return;
}

// Returns the top element without popping it
int Top(STACK *s){

    if(isEmpty(s)){

        //printf("Empty STACK\n");
        exit(1);
    }

    int val=s->head->data;
    return val;

}


// Returns the last element from the stack , then pops it
int Pop(STACK *s)
{


    if(isEmpty(s))
    {

        //printf("EMPTY STACK");
        exit(1);
    }

    int val;

    LIST *elem=s->head;
    val=elem->data;

    s->head=elem->next;
    free(elem);

    return val;
}


// Prints the stack
void PrintStack(STACK *s)
{

    if(isEmpty(s))
    {
        printf("EMPTY STACK");
        return;
    }

    LIST *crawl=s->head;
    printf("%d ",crawl->data);
    crawl=crawl->next;
    while(crawl)
    {

        printf("-> %d",crawl->data);
        crawl=crawl->next;
    }

    printf("\n");

    return;

}



#endif // STACK_H_INCLUDED
