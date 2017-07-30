#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x;

	printf("Enter the number of terms: ");
	scanf("%d", &x);

	int array[x];

	int i;
	for(i = 0; i < x; i++)
	{
		array[i] = 0;
	}

	array[0] = 0;
	array[1] = 1;

	for(i = 2; i < x; i++)
	{
		array[i] = array[i-1] + array[i-2];
	}

	int sum;
	printf("First %d terms of Fibonacci numbers are:\n",x);
	for(i = 0; i < x; i++)
	{
		printf("%d\n",array[i]);
		sum += array[i];
	}

	printf("\n");
	printf("The sum value of the above sequence is:\n%d",sum);
	printf("\n\n");
}
