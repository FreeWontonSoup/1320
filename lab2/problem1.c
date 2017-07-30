#include <stdio.h>

void sort(int a[])
{
    int i, j, temp;
    //int* sorter = &a;
    for(i = 0; i < 17; i++)     //this function sorts the array from least to greatest (bubble sort)
    {
        for(j = 0; j < 17; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void main(void)
{
    int i, j;

    int A[18];
    int B[5];

    for(i = 0; i < 13; i++)         //puts integers user enters into array A
    {
        int num;
        printf("Enter an integer into array A: ");
        scanf("%d",&num);
        A[i] = num;
    }

    for(i = 0; i < 5; i++)          //puts integers user enters into array B
    {
        int num;
        printf("Enter an integer into array B: ");
        scanf("%d",&num);
        B[i] = num;
    }

    for(i = 13; i < 18; i++)        //merges array B into array A
    {
        A[i] = B[i-13];
    }

    sort(A);                        //sorts array A

    for(i = 0; i < 18; i++)         //prints out array A
    {
        if(i != 17)
        {
            printf("%d,",A[i]);
        }
        else
        {
            printf("%d",A[i]);
        }
    }

    printf("\n");

}
