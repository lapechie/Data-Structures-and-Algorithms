#include <stdio.h>
#include <stdlib.h> 

struct node
{
    int data;
    struct node *next;
};

struct node *head = 0;
struct node *tail = 0;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = x;
    newnode->next = 0;

    if(head == 0 && tail == 0)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

void display()
{
    struct node *temp;
    temp = head;
    if(head == 0 && tail == 0)
    {
        printf("List is empty\n");
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


void dequeue()
{   
    struct node *temp;
    temp = head;

    if(head == 0 && tail == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        head = head->next;
        free(temp);
    }
}

void peak()
{
    
    if(head == 0 && tail == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("%d\n", head->data);
    }
}

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    display();
    dequeue();
    display();
    peak();

    return 0;
}