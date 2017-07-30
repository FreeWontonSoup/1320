#include <stdio.h>

int reverse(int num)
{
    int r, rev;
    r = 0;
    rev = 0;
    while(num > 0)
    {
        r = num % 10;       //take the last digit of the number
        rev = rev * 10 + r;    //this adds to the reverse so it has the correct amount of places (hundreds number is still hundreds in rev)
        num = num / 10;        //chops off the last digit of num
    }
    return rev;
}

void main(void)
{
    int num, rev, sum;
    printf("Enter an integer: ");       //take in an integer from the user
    scanf("%d",&num);
    rev = reverse(num);                 //reverse the num entered by the user and store it in rev
    sum = num + rev;                    //sum the original number and the reversed
    printf("%d\n",sum);
}
