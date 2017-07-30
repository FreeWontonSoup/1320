#include <stdio.h>
#include <stdlib.h>

void main()
{
	int array[10];
	int i, count;
	for(i = 0; i < 10; i++)	//this loop fills an array of size 10 with numbers that the user enters
	{
		int x;
		printf("Enter an integer: ");
		scanf("%d",&x);
		array[i] = x;
	}

	int num;
	printf("Enter an x: ");
	scanf("%d",&num);	//this scanner sets num to the value of whatever the user types in

	int j;
	for(i = 0; i < 10; i++)
	{
		for(j = i+1; j < 10; j++)
		{
			if(array[i]*array[i] + array[j]*array[j] == num*num)
			{
				count++;
				printf("(%d, %d)",i,j);
				printf("\n");
			}
		}
	}

	if(count == 0)
	{
		printf("There are no such pairs.");
		printf("\n");
	}



/*	for(int i = 0; i < 5; i++)
	{
		printf("%d", array[i]);
	}
	*/
}
