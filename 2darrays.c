#include <stdio.h>

int main()
{
    int a[3][3] = {6,2,5,0,1,3,4,9,8};
    int *p;

    p = &a[0][0];

    printf("%p\n", a[0]);
    return 0;
}