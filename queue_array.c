#include <stdio.h>
#include <stdlib.h> 

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear == N -1 )
    {
        printf("Overflow");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("List empty\n");
    }
    else if(rear == front)
    {
        front = rear = -1;
    }
    else
    {   
        printf("Deleted data is: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if(rear == -1 && front == -1)
    {
        printf("List is empty\n");
    }
    else
    {
        for(int i = front; i < rear + 1; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

void peak()
{
    if(rear == -1 && front == -1)
    {
        printf("List is empty\n");
    }
    else
    {
       printf("%d\n", queue[front]);
    }     
}

int main()
{

    return 0;
}
