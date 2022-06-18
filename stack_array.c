#include <stdio.h>
#include <stdlib.h> 

#define N 5
int stack[N];
int top = -1;

void push()
{
    int x;
    
    printf("Enter data: \n");
    scanf("%d", &x);
    if(top == N - 1)
    {
        printf("Overflow Condition\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    int x;

    if(top == -1)
    {
        printf("Underflow Condition\n");
    }
    else
    {
        x = stack[top];
        top--;
        printf("Popped item is: %d \n", x);
    }
}

void peak()
{
    int x;
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        x = stack[top];
        printf("Top item is: %d \n", x);
    }
}

void display()
{
    int x;
    int i;
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(i = top; i >= 0; i--)
        {
            x = stack[i];
            printf("%d\n", x);
        }
    }
}

int main()
{
    int choice;
    do
    {
        printf("Enter choice: 1:Push, 2:Pop, 3:Peak, 4:Display\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peak();
                    break;
            case 4: display();
                    break;
            default: printf("Invalid choice");
        }
    }
    while (choice != 0);

    return 0;
}