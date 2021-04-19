#include<stdio.h>
int euclid(int a , int b)
{
    int q,r;

    while(b>0)
{
    q = a/b;
    r = a-q*b;
    a = b;
    b = r;
}
return a;
}

int main()
{
    int a = 288;
    int b = 108;
    printf("euclid(%d,%d) = %d",a,b,euclid(a,b));
    return 0;
}
