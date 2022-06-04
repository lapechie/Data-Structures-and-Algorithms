#include <stdio.h>

int main()
{
    int a[50];
    int size;
    int pos;
    int num;

    printf("What is the size of array: \n");
    scanf("%d", &size);

    if(size > 50)
    {
        printf("Overflow condition \n");
    }
    else
    {
        printf("What are elements of array: \n");
        for(int i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }
        
        // traverse the array
        printf("Elements of array are: \n");
        for(int i = 0; i < size; i++)
        {
            printf("%d\n", a[i]);
        }
    }

    printf("Enter number to insert in array: \n");
    scanf("%d", &num);
    printf("Enter position to insert: \n");
    scanf("%d", &pos);

    // shifting and inserting
    for(int i = size - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = num;
    size++;

    // traverse the array
    printf("Elements of array are: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }

    // deletion
    printf("From which position do you want to delete an element: \n");
    scanf("%d", &pos);

    if(pos <= 0 || pos > size)
    {
        printf("Invalid position. Position out of bounds");
    }
    else
    {
        for(int i = pos - 1; i < size - 1; i++)
        {
        a[i] = a[i + 1];
        }
        size--;  
    }

    // traverse the array
    printf("Elements of array are: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}