#include <stdio.h>
#include <stdlib.h> 

struct node
{
    int a;
    int b;
};

int main()
{
    struct node *node1;
    struct node *node2;
    struct node *node3;
    
    node3->a = 1;

    node1 = node2 = node3;

    printf("%d\n", node1->a);
 
}