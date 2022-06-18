#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void create()
{
    head = 0;
    
    int choice = 1;
    struct node *temp;

    while(choice)
    {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: \n");
        scanf("%d", &newnode->data);

        if (head == 0)
        {
            head = temp = newnode;
            newnode->next = 0;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        temp->next = head;
        
        printf("Do you want to continue? (1, 0) \n");
        scanf("%d", &choice);
    }
}

void display()
{
    struct node *temp;
    printf("-------------------");
    if(head == 0)
    {
        printf("List is empty");
    }
    else
    {  
        temp = head;
        while(temp->next != head)
        {
            printf("\n%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void insertAtBeg()
{   
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node*));
    struct node *temp;
    temp = head;

    printf("Enter data to enter at start: \n");
    scanf("%d", &newnode->data);
    
    newnode->next = head;     
    //head->next = newnode;
    head = newnode;
}

int main()
{
    create();
    
    display();

    insertAtBeg();

    display();
    return 0;
}