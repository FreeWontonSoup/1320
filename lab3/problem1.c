#include <stdio.h>
#include <string.h>

void searchFirst(int numRecords, char firstName[][21], char lastName[][21], float scores[]);
void searchLast(int numRecords, char firstName[][21], char lastName[][21], float scores[]);
void sortScore(int numRecords, char firstName[][21], char lastName[][21], float scores[]);
void sortLast(int numRecords, char firstName[][21], char lastName[][21], float scores[]);
void findMaxScore(int numRecords, char firstName[][21], char lastName[][21], float scores[]);
void findMinScore(int numRecords, char firstName[][21], char lastName[][21], float scores[]);

int inputNumRecords()
{
    int i, numRecords, run;
    run = 1;

    while(run == 1)
    {
        printf("Please indicate the number of records you want to enter (min 5, max 15): \n\n");
        scanf("%d",&numRecords);
        if(numRecords < 5 || numRecords > 15) //takes in number of records. prompts user again if number isn't within range
        {
            printf("\n");
            printf("Number not in range, try again.\n");
        }
        else
        {
            printf("\n");
            return numRecords;
        }
    }
}

void records(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int row, col, i, j;

    printf("Please input records of students enter a new line after each record, with following format first name last name score\n");

    for(row = 0; row < numRecords; row++)
    {
        printf("First Name: ");             //array of first names
        scanf("%s",firstName[row]);
        printf("Last Name: ");
        scanf("%s",lastName[row]);          //array of last names

        float score;
        printf("Score: ");
        scanf("%f",&score);                 //array of scores
        scores[row] = score;
        printf("\n");
    }


}

void printer(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, j, row, col;

    for(row = 0; row < numRecords; row++)
    {
        //print firstName array
        printf("First Name: %s, Last Name: %s,",firstName[row],lastName[row]);      //prints records from all 3 arrays
        printf(" Score: %f",scores[row]);
        printf("\n");
    }
    printf("\n\n");
}


void functionalities(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, input;
    i = 1;
    while(i != 0)
    {
        printf("\n");
        printf("Print records (press 1)\n");
        printf("Search by first name (press 2)\n");
        printf("Search by last name (press 3)\n");
        printf("Sort by score (press 4)\n");
        printf("Sort by last name (press 5)\n");
        printf("Find Max Score (press 6)\n");
        printf("Find Min Score (press 7)\n");
        printf("Exit the program (press 0)\n");
        printf("\n");
        scanf("%d",&input);     //takes input to determine which function to run

        if(input == 1)
        {
            printer(numRecords, firstName, lastName, scores);
        }
        else if(input == 2)
        {
            searchFirst(numRecords, firstName, lastName, scores);
        }

        else if(input == 3)
        {
            searchLast(numRecords, firstName, lastName, scores);
        }
        else if(input == 4)
        {
            sortScore(numRecords, firstName, lastName, scores);
        }
        else if(input == 5)
        {
            sortLast(numRecords, firstName, lastName, scores);
        }
        else if(input == 6)
        {
            findMaxScore(numRecords, firstName, lastName, scores);
        }

        else if(input == 7)
        {
            findMinScore(numRecords, firstName, lastName, scores);
        }
        else if(input == 0)
        {
            break;
        }
    }

}


void searchFirst(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, j, row, col, check;
    char first[21];
    check = 0;
    printf("Enter the first name you want to search for: ");

    scanf("%s",first);                  //searches for the name the user entered

    for(row = 0; row < numRecords; row++)       //loops through the first name array to find name
    {
        if(strcmp(first,firstName[row]) == 0)      //if the strcmp of the two strings returns 0, means it is a match
        {
            printf("First Name: %s, Last Name: %s,",firstName[row],lastName[row]);      //print out the records for that person
            printf(" Score: %f",scores[row]);
            printf("\n");
            check = 1;
        }
    }
    if(check == 0)
    {
        printf("This person could not be found.\n");
    }

}

void searchLast(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, j, row, col, check;
    char last[21];
    check = 0;
    printf("Enter the last name you want to search for: ");

    scanf("%s",last);               //searches for the name the user entered

    for(row = 0; row < numRecords; row++)       //loops through the last name array to find the name
    {
        if(strcmp(last,lastName[row]) == 0)     //if the strcmp of the two strings returns 0, means it is a match
        {
            printf("First Name: %s, Last Name: %s,",firstName[row],lastName[row]);      //print out the records for that person
            printf(" Score: %f",scores[row]);
            printf("\n");
            check = 1;
        }
    }
    if(check == 0)
    {
        printf("This person could not be found.\n");
    }
}

void sortScore(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, j;

    char temp2[21];     //temp arrays to hold values to swap
    char temp3[21];

    for(i = 0; i < numRecords - 1; i++)     //loop through arrays firstname and lastname and sort by score
    {
        for(j = 0; j < numRecords - 1; j++)
        {
            if(scores[j+1] < scores[j])
            {
                int temp = scores[j];           //using bubble sort sort the firstName, lastName, and score arrays by score
                scores[j] = scores[j+1];        //in other words, the arrays for the names will be sorted corresponding to their score
                scores[j+1] = temp;             //and the scores array will be sorted by scores
                strcpy(temp2,firstName[j]);
                strcpy(firstName[j],firstName[j+1]);
                strcpy(firstName[j+1],temp2);           //strcopy allows me to set the strings = to new values
                strcpy(temp3,lastName[j]);
                strcpy(lastName[j],lastName[j+1]);
                strcpy(lastName[j+1],temp3);
            }
        }
    }
    printer(numRecords, firstName, lastName, scores);
}

void sortLast(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, j;

    char temp2[21];     //temp arrays to hold values
    char temp3[21];

    for(i = 0; i < numRecords - 1; i++)         //loop through arrays to sort by lastName
    {                                           //arrays will be bubble sorted and everything will be sorted corresponding to
        for(j = 0; j < numRecords - 1; j++)     //the user's last name
        {
            if(strcmp(lastName[j],lastName[j+1]) > 0)
            {
                int temp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = temp;
                strcpy(temp2,firstName[j]);
                strcpy(firstName[j],firstName[j+1]);
                strcpy(firstName[j+1],temp2);           //bubble sorting
                strcpy(temp3,lastName[j]);
                strcpy(lastName[j],lastName[j+1]);
                strcpy(lastName[j+1],temp3);
            }
        }
    }
    printer(numRecords, firstName, lastName, scores);
}

void findMaxScore(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, j, max;
    max = 0;

    for(i = 0; i < numRecords; i++)
    {
        int num;
        num = scores[i];
        if(num > max)               //set max to the highest score
        {
            max = num;
        }
    }

    for(i = 0; i < numRecords; i++)     //find where the max is so the user with max score can be printed
    {
        if(scores[i] == max)
        {
            printf("First Name: %s, Last Name: %s,",firstName[i],lastName[i]);
            printf(" Score: %f",scores[i]);
            printf("\n");
        }
    }

}

void findMinScore(int numRecords, char firstName[][21], char lastName[][21], float scores[])
{
    int i, j, min;
    min = scores[0];

    for(i = 0; i < numRecords; i++)
    {
        int num;
        num = scores[i];
        if(num < min)               //set min to the lowest score
        {
            min = num;
        }
    }

    for(i = 0; i < numRecords; i++)     //find where the min is so the user with min score can be printed
    {
        if(scores[i] == min)
        {
            printf("First Name: %s, Last Name: %s,",firstName[i],lastName[i]);
            printf(" Score: %f",scores[i]);
            printf("\n");
        }
    }
}


int main(void)
{

    int numRecords;
    numRecords = inputNumRecords();     //numrecords will be the number of people
    float scores[numRecords];
    char firstName[numRecords][21], lastName[numRecords][21];   //all arrays are made here so they can be changed by all functions
    records(numRecords, firstName, lastName, scores);
    functionalities(numRecords, firstName, lastName, scores);   //functionalities will handle everything else
    return 0;
}
