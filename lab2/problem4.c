#include <stdio.h>

void main()
{
    char string[11];    //11 instead of 10 because of the \0
    char letters[10];   //this will hold the letters that repeat

    int i, j, k;

    for(i = 0; i < 10; i++)
    {
        letters[i] = '0';       //fills with 0 to get rid of junk
    }

    printf("Enter a string of length 10: ");    //this program only works for strings length 10
    fgets(string,11,stdin);                     //uses fgets to take a string even with spaces of length 10

    int spot;       //spot keeps track of where to place repeated letters in the letters array
    spot = 0;
    for(i = 0; i < 11; i++)     //nested loop compares every letter in the array and looks for repeats
    {
        for(j = i; j < 11; j++)
        {
            if(i != j)          //you don't want to count looking in the same spot as a repeat
            {
                if(string[i] == string[j])
                {
                    for(k = 0; k < 10; k++)     //if it finds a repeat letter, loop through the letters array to see if the repeated letter
                    {                           //has already been accounted for. if it has, don't add it into the array again
                        if(letters[k] == string[i])
                        {
                            break;
                        }
                        else if(k == 9 && letters[k] != string[i])     //if the letter does not exist in the other array, add it in after
                        {                                              //the last letter that has been added in
                            letters[spot] = string[i];
                            spot++;
                        }
                    }
                }
            }
        }
    }

    int letters2[spot];     //spot also holds the value of how many repeated letters there are
    for(i= 0; i < spot; i++)    //this loop adds the letters into another array but without any extra blank spaces
    {
        letters2[i] = letters[i];
    }

    if(spot == 0)
    {
        printf("No character is repeated\n");
    }
    else
    {
        printf("Number of characters repeated: %d",spot);   //print the results
        printf("\n");
        printf("Characters repeated: ");
        for(i = 0; i < spot; i++)       //print the letters that repeat
        {
            if(i == spot - 1)           //just a check to see when a comma should be printed
            {
                printf("%c",letters2[i]);
            }
            else
            {
                printf("%c, ",letters2[i]);
            }
        }
        printf("\n");
    }

}
