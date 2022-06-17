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

void deleteFromBeg()
{
    struct node *temp;
    temp = head;
    head = head->next;
    head->prev = 0;
    free(temp);

}

void deleteFromEnd()
{
    struct node *temp;
    temp = tail;
    tail = tail->prev;
    tail->next = 0;
    free(temp);
}

void deleteFromPos()
{
    struct node *temp;
    int pos;
    int i = 1;

    printf("Enter position to delete: \n");
    scanf("%d", &pos);

    temp = head;
    while( i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void reverse_ll()
{
    struct node *temp;
    struct node *nextnode;

    temp = head;

    while(temp != 0)
    {
        nextnode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextnode;
        temp = nextnode;
    }
    temp = head;
    head = tail;
    tail = head;

}

int main()
{   
    
    create();

    display();
    reverse_ll();
    display();


    return 0;
}