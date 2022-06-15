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

void display_ll(struct node* head)
{
    printf("--------------------------------\n");
    struct node *temp;
    temp = head;
    while(temp != 0)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
}

void delete_from_beg(struct node* head)
{
    struct node *temp;
    temp = head;
    head = head->next; 
    free(temp); 
    display_ll(head);
}

void delete_from_end()
{
    
}

void insert_beg(struct node* head)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert:\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    display_ll(head);
}

void insert_end(struct node* head)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    printf("Enter data you want to insert:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    temp = head;

    while(temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    display_ll(head);
}

void insert_at_loc(struct node* head)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    int pos;
    int i = 1;
    printf("Enter position to insert:\n");
    scanf("%d", &pos);
    temp = head;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    printf("Enter data you want to insert:\n");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
    display_ll(head);
}

void main()
{
    struct node *head;
    struct node *newnode;
    struct node *temp;
    head = NULL;
    int choice;
    // creating a linked list
    while(choice)
    {   
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data: \n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if(head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to coninue? (0,1) \n");
        scanf("%d", &choice);
    }

    display_ll(head);

    //insert_beg(head);

    //insert_end(head);

    //insert_at_loc(head);

    delete_from_beg(head);

}