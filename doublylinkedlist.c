#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;
struct node *tail;

void create()
{
    int choice = 1;
    head = 0;    
    struct node *temp;
    struct node *newnode;

    // capture data    
    while(choice)
    {   
        
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        
        newnode->prev = 0;
        newnode->next = 0;

        if(head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue? (1,0)\n");
        scanf("%d", &choice);
    }
}

void display()
{
    struct node *temp;
    temp = head;
    printf("--------------------------------\n");
    while(temp != 0)
    {
        printf("\n%p\n", temp->next);
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
}

void insertAtBeg()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertAtPos()
{
    int pos;
    int i = 1;

    printf("Enter Position: \n");
    scanf("%d", &pos);

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    struct node *temp;
    temp = head;
    while(i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;

    temp->next = newnode;
    newnode->next->prev = newnode;
}

int main()
{   
    
    create();

    display();
    insertAtPos();
    display();


    return 0;
}