#include <stdio.h>

void sort(int a[])
{
    int i, j, temp;
    //int* sorter = &a;
    for(i = 0; i < 19; i++)     //this function sorts the array from least to greatest (bubble sort)
    {
        for(j = 0; j < 19; j++)
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

void main()
{
    int i, j, target,count;
    int nums[20];
    int sorted[20];

    for(i = 0; i < 20; i++)
    {
        int num;
        printf("Enter an integer for the array: ");     //fill in array with integers from users
        scanf("%d",&num);
        nums[i] = num;
    }

    printf("Enter a target integer: ");                 //take in a target integer from user
    scanf("%d",&target);

    sort(nums);     //calls the sort function and sorts the array. since the array parameter in the function techincally
                    //changing it in the function changes the original as well bc it points to the original

    for(i = 0; i < 20; i++)     //nested loop that compares all numbers to see if the addition of them ='s the target
    {
        for(j = i; j < 20; j++)
        {
            if(i != j)
            {
                if(nums[i] + nums[j] == target)
                {
                    printf("(%d,%d) ",nums[i],nums[j]);
                    count++;
                }
            }
        }
    }

    if(count == 0)  //count that tallies the amount of pairs, useful to see if there are no pairs
    {
        printf("No pair of integers in the given array can be summed to the target value");
    }
}
