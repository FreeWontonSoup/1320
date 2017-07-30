#include <stdio.h>

void sort(char let[5][4])
{
    int i, j, k, l, ret;
    char word1[4];
    char word2[4];

    for(k = 0; k < 4; k++)      //this outter loop exists to run these 2 inner loops. the outter loop is basically
    {                           //required to make sure this bubble sort in the most inner loop fully goes through
                                //the 2d matrix and test the if condition on every element
        for(i = 0; i < 4; i++)
        {
            for(j = 0; j < 4; j++)  //the two inner loops are just normal loops that go through a 2d matrix
            {
                word1[j] = let[i][j];
                word2[j] = let[i+1][j]; //this puts together the row and row+1 into a word so they can be compared (bubble sort)
                ret = strcmp(word1,word2);
                if(ret > 0)
                {
                    char temp;          //swapping of rows
                    temp = let[i][j];
                    let[i][j] = let[i+1][j];
                    let[i+1][j] = temp;
                }
            }
        }
    }
}

int main(void)
{
    int row, col, i, j;
    char let[5][4];

    printf("Enter the 5 strings one by one delimited by new line.\n\n");
    //takes in a string and deconstructs every character so it has a spot n the 2d array
    for(row = 0; row < 5; row++)
    {
        char word[4];
        scanf("%s",word);
        for(col = 0; col < 4; col++)
        {
            char letter;
            letter = word[col];
            let[row][col] = letter;
        }
    }

    sort(let);  //sorts the 2d matrix
    printf("\n");
    printf("Sorted strings: \n\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%c",let[i][j]);
        }
        printf("\n");
    }
    return 0;
}
