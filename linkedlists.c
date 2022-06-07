#include <stdio.h>
#include <stdlib.h> 
// types of linked lists
// singly
// doubly
// circular
// doubly circular

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *head;
    struct node *newnode;
    struct node *temp;
    head = NULL;
    int choice;
    
    while (choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data: \n");
        scanf("%d\n", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to coninue? (0,1) \n");
        scanf("%d\n", &choice);
    }
    temp = head;
    while(temp != 0)
    {
        printf("%d\n", temp->data);
    }
}