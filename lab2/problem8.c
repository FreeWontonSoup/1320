#include <stdio.h>

// Function to check prime number
int CheckPrime(int n)
{
    int i, isPrime = 1;
    for(i = 2; i < n; i++)  //checks if a number is prime, returns 1 if n is prime 0 if it isn't
    {
        if(n % i == 0)
        {
            isPrime = 0;
        }
    }
    return isPrime;
}

void main(void)
{
    int i, j, num, countPrime;
    num = 0;
    countPrime = 0;

    printf("Enter an integer: ");
    scanf("%d",&num);

    int primes[num+2];
    for(i = 0; i < num+2; i++)    //clears the junk so the array can hold prime numbers but also includes 0's
    {
        primes[i] = 0;
    }
    
    int spot2;
    spot2 = 0;
    for(i = 2; i < num; i++)
    {
        int prime = CheckPrime(i);  //gets prime numbers all the way up to num and counts how many there are
        if(prime == 1)
        {
            primes[spot2] = i;
            countPrime++;
            spot2++;
        }
    }

    int primeNums[countPrime];  //puts all prime numbers in own array getting rid of the 0's
    int spot;
    spot = 0;
    for(i = 0; i < num; i++)
    {
        if(primes[i] != 0)
        {
            primeNums[spot] = primes[i];
            spot++;
        }
    }

    int count;
    count = 0;
    for(i = 0; i < countPrime; i++)
    {
        for(j = i; j < countPrime; j++)
        {
            if(primeNums[i] + primeNums[j] == num)      //uses the prime number array and does every comparison (without repeats)
            {                                           //to determine what prime numbers add to = num
                count++;
                printf("%d = %d + %d",num,primeNums[i],primeNums[j]);
                printf("\n");
            }
        }
    }

    if(count == 0)
    {
        printf("This number has no prime numbers that add to it.\n");
    }
}
