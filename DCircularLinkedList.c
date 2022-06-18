#include <stdio.h>
#include <stdlib.h> 

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head, *tail;

void create()
{
    head = 0;
    int choice = 1;
    struct node *temp;
    struct node *newnode;

    while(choice)
    {
        
        newnode = (struct node*)malloc(sizeof(struct node*));

        printf("Enter Data: \n");
        scanf("%d", &newnode->data);
        if(head == 0)
        {
            head = temp = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
        }
        printf("Do you want to continue? (1, 0)");
        scanf("%d", &choice);
    }
    newnode->next = head;
    head->prev = newnode;
    tail = newnode; 
}

void display()
{
    struct node *temp;
    temp = head;
    printf("-----------------------");
    while(temp->next != head)
    {
        
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    printf("Head is: %d\n", head->data);
    printf("Tail is: %d\n", tail->data);
}

int main()
{
    create();
    display();

    return 0;
}