#include <stdio.h>

int f(int n)
{
    int first;
    first = 1;
    if(n == first)          //recursive function that calculates the nth term
    {
        return n;
    }
    return f(n-1) * f(n-1) + 1;
}

int main(void)
{
    int i, n;
    printf("Enter an integer n for the nth term: ");        //user input
    scanf("%d",&n);
    for(i = 1; i <= n; i++)         //for loop that prints out every value of the series up to n
    {
        printf("%d ",f(i));
    }
    return 0;
}
