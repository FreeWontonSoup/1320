#include <stdio.h>
#include <stdlib.h>

void main()
{
  int x;
  printf("Number? ");
  scanf("%d",&x);

  int isPrime;
  isPrime = 1;

  int i;
  for(i = 2; i < x; i++)
  {
      if(x % i == 0)
      {
          isPrime = 0;
      }
  }

  int j;
  if(isPrime == 1)
  {
      printf("The prime factors of %d are 1 and %d",x,x);
      printf("\n\n");
  }
  else
  {
      printf("The prime factorization of %d is ",x);
      for(i = 2; i < x; i++)
      {
        for(j = 2; j <= x/2; j++)
        {
          if(x % j == 0)
          {
            printf("%d*",j);
            x = x/j;
            break;
          }
        }
      }
      printf("%d\n",x);
  }



  int x2;
  printf("Number? ");
  scanf("%d",&x2);

  int isPrime2;
  isPrime2 = 1;

  for(i = 2; i < x2; i++)
  {
      if(x2 % i == 0)
      {
          isPrime2 = 0;
      }
  }

  if(isPrime2 == 1)
  {
      printf("The prime factors of %d are 1 and %d",x2,x2);
      printf("\n\n");
  }
  else
  {
      printf("The prime factorization of %d is ",x2);
      for(i = 2; i < x2; i++)
      {
        for(j = 2; j <= x2/2; j++)
        {
          if(x2 % j == 0)
          {
            printf("%d*",j);
            x2 = x2/j;
            break;
          }
        }
      }
      printf("%d\n",x2);
  }
}
