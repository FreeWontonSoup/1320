#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, num, temp, spot, spotP;
    int array[10];

    for(i = 0; i < 10; i++)
    {
        printf("Enter an integer: ");
        scanf("%d",&num);
        array[i] = num;
    }

    for(j = 0; j < 9; j++)
    {
        for(i = 0; i < 9; i++)
        {
            spot = array[i];
            spotP = array[i + 1];
            if(spot > spotP)
            {
                temp = spot;
                array[i] = spotP;
                array[i + 1] = temp;
            }
        }
    }

    printf("Sorted list: ");
    printf("\n");
    printf("{");
    for(i = 0; i < 10; i++)
    {
        printf("%d ",array[i]);
    }
    printf("}");
    printf("\n");
}
