#include <stdio.h>
#include <stdlib.h> 

struct node
{   
    int data;
    struct node *next;
};

struct node *temp;

void display_ll(struct node* head)
{
    printf("--------------------------------\n");
    temp = head;
    while(temp != 0)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
}

void delete_from_beg(struct node* head)
{
    temp = head;
    head = head->next; 
    free(temp); 
    display_ll(head);
}

void delete_from_end(struct node* head)
{
    struct node* prevnode;
    temp = head;

    while(temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = 0;
    free(temp);
    display_ll(head);
}

void delete_from_pos(struct node* head)
{
    struct node* nextnode;
    int pos;
    int i = 1;

    temp = head;
    printf("Enter position to delete:\n");
    scanf("%d", &pos);

    while(i < pos -1)
    {   
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    display_ll(head);
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

void length_ll(struct node* head)
{
    temp = head;
    int i = 1;

    while(temp->next != 0)
    {
        temp = temp->next;
        i++;
    }
    printf("%d", i);
}

void reverse_ll(struct node* head)
{
    struct node* prevnode;
    struct node* nextnode;

    prevnode = 0;
    temp = nextnode = head;

    while(nextnode != 0)
    {   
        nextnode = nextnode->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }
    head = prevnode;
    display_ll(head);
}

int main()
{
    struct node *head;
    struct node *newnode;
    
    head = 0;
    int choice = 1;
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

    //delete_from_beg(head);

    //delete_from_pos(head);

    //length_ll(head);

    reverse_ll(head);
    return 0;
    
}