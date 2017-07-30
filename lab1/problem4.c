#include <stdio.h>
#include <stdlib.h>

void main()
{
  int rows, cols, i, j, num, sum, counter, add1, add2;
  printf("Enter number of rows: ");
  scanf("%d",&rows);
  printf("Enter number of cols: ");
  scanf("%d",&cols);

  int array[rows][cols];
  int array2[rows][cols];

  printf("Enter values for matrix 1: ");
  printf("\n");
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
       scanf("%d",&num);
       array[i][j] = num;
    }
  }

  printf("Enter values for matrix 2: ");
  printf("\n");
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
       scanf("%d",&num);
       array2[i][j] = num;
    }
  }

  printf("Sum of 2 matrixes should be: ");
  printf("\n");
  for(i = 0; i < rows; i++)
  {
      for(j = 0; j < cols; j++)
      {
          add1 = array[i][j];
          add2 = array2[i][j];
          sum = add1 + add2;
          if(j == 0 && i != 0)
          {
              printf("\n");
          }
          printf("%d ",sum);
      }
  }
  printf("\n");

}
