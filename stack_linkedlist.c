#include <stdio.h>
#include <stdlib.h> 

struct node
{
    int data;
    struct node* next;
};

struct node* top = 0;;

void push(int x)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void display()
{
    struct node *temp;
    temp = top;

    if(top == 0)
    {
        printf("Stack is empty \n");
    }
    else
    {   
        while(temp != 0)
        {
            printf("\n%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void peak()
{
    printf("\n%d\n", top->data);
}

void pop()
{
    struct node *temp;
    temp = top;
    top = top->next;
    free(temp);
}

int main()
{
    push(6);
    push(7);
    push(9);
    push(3);
    display();
    peak();
    return 0;
}