#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate(int size, char ***firstNames, char ***lastNames, float ***scores);
void printer(int size, char ***firstNames, char ***lastNames, float ***scores);
void add(int size, char ***firstNames, char ***lastNames, float ***scores);
void del(int size, char ***firstNames, char ***lastNames, float ***scores);
void searchLast(int size, char ***firstNames, char ***lastNames, float ***scores);
void median(int size, char ***firstNames, char ***lastNames, float ***scores);
void sortScore(int size, char ***firstNames, char ***lastNames, float ***scores);
void functionalities(int size, char ***firstNames, char ***lastNames, float ***scores);

void median(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    int row, count, i, j;
    float *combine;     //this single pointer is going to collect all scores excluding nulls so they can be compared

    count = 0;
    for(row = 0; row < size; row++)
    {
        if((*scores)[row] != NULL)      //if the spot in scores is not null, count up
        {                               //this will give me the count of how many numbers there are
            count++;                    //not including the elements that get deleted
        }
    }
    combine = (float*)calloc(count,sizeof(float));      //size of the pointer will be the count

    count = 0;
    for(row = 0; row < size; row++)
    {
        if((*scores)[row] != NULL)          //loops through the scores again and makes sure it grabs numbers
        {                                   //and doesn't mess with anything that has been deleted
            combine[count] = (*scores)[row][0];
            count++;                        //count now keeps track of where it should place the numbers in combine
        }
    }

    for(i = 0; i < count-1; i++)
    {
        for(j = 0; j < count-1; j++)
        {
            if(combine[j] > combine[j+1])
            {
                float temp = combine[j];            //bubble sorts the scores in combine
                combine[j] = combine[j+1];
                combine[j+1] = temp;
            }
        }
    }

    if(count % 2 != 0)
    {
        printf("%.2f is the median score. There are %d students above this score.\n",combine[count/2],(count-1)/2);     //print out median
        //the count/2 gets the middle spot in the odd numbered score list and the (count-1)/2 gives the amount of students
    }   //above the median
    else
    {
        //this handles the median if there is an even amount of numbers, prints same thing
        float avg;
        int mid;
        mid = count/2;
        avg = (combine[mid] + combine[mid-1])/2.0;
        printf("%f is the median score. There are %d students above this score.\n",avg,count/2);
        free(combine);
        combine = NULL;
    }
}

void sortLast(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    int i, j, row, count = 0;
    char **firsts;              //will hold values from the original pointers so they can be sorted and swapped in the function
    char **lasts;               //and then placed back into the original pointers but in order
    float *nums;                //the reason why i don't just do the comparison directly on the original pointers
    for(row = 0; row < size; row++) //is because of the possibility of deleted null records
    {
        if((*lastNames)[row] != NULL)
        {
            count++;            //amount of names that will be sorted
        }
    }
    firsts = (char**)malloc(count*sizeof(char*));
    lasts = (char**)malloc(count*sizeof(char*));
    nums = (float*)calloc(count,sizeof(float));
    for(row = 0; row < count; row++)
    {
        firsts[row] = (char*)malloc(21*sizeof(char));       //allocating memory to hold the names and scores
        lasts[row] = (char*)malloc(21*sizeof(char));
    }

    count = 0;
    for(row = 0; row < size; row++)
    {
        if((*lastNames)[row] != NULL)
        {
            strcpy(firsts[count],(*firstNames)[row]);
            strcpy(lasts[count],(*lastNames)[row]);         //placing the values from the original pointers into the
            nums[count] = (*scores)[row][0];                //function ones
            count++;
        }
    }

    for(i = 0; i < count-1; i++)
    {
        for(j = 0; j < count-1; j++)
        {
            if(strcmp(lasts[j],lasts[j+1]) > 0)
            {
                char *ftemp = (char*)malloc(21*sizeof(char));
                char *ltemp = (char*)malloc(21*sizeof(char));
                float temp;
                strcpy(ftemp,firsts[j]);
                strcpy(ltemp,lasts[j]);
                temp = nums[j];
                strcpy(firsts[j],firsts[j+1]);          //bubble sort by last name
                strcpy(firsts[j+1],ftemp);              //sorts the pointers made in the function and also
                strcpy(lasts[j],lasts[j+1]);            //rearranges the first names/scores too so things are together
                strcpy(lasts[j+1],ltemp);
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    count = 0;
    for(row = 0; row < size; row++)
    {
        if((*lastNames)[row] != NULL)
        {
            strcpy((*firstNames)[row],firsts[count]);       //place the values from the pointer in the function back into
            strcpy((*lastNames)[row],lasts[count]);         //the original pointers but this time it will be in order by
            (*scores)[row][0] = nums[count];                //last name
            count++;
        }
    }
    printer(size, &(*firstNames), &(*lastNames), &(*scores));

    for(i = 0; i < count; i++)
    {
        free(firsts[i]);
        firsts[i] = NULL;
        free(lasts[i]);
        lasts[i] = NULL;
    }
    free(nums);
    nums = NULL;
}

void sortScore(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    int i, j, row, count;
    float *combine;
    char **fnames;          //double pointers are here so everything can be sorted by score accordingly together with
    char **lnames;          //their respective names, we can't directly compare the original pointers bc of
                            //possible null spaces
    count = 0;
    for(i = 0; i < size; i++)
    {
        if((*scores)[i] != NULL)
        {
            count++;        //count again to see how many numbers we will be taking in to sort
        }
    }
    fnames = (char**)malloc(count*sizeof(char*));
    lnames = (char**)malloc(count*sizeof(char*));
    combine = (float*)calloc(count,sizeof(float));

    for(row = 0; row < count; row++)
    {
        fnames[row] = (char*)malloc(21*sizeof(char));     //adding columns
        lnames[row] = (char*)malloc(21*sizeof(char));
    }

    count = 0;
    for(i = 0; i < size; i++)
    {
        if((*scores)[i] != NULL)
        {
            combine[count] = (*scores)[i][0];
            strcpy(fnames[count],(*firstNames)[i]);     //placing the values from original pointers into function made ones
            strcpy(lnames[count],(*lastNames)[i]);
            count++;
        }
    }

    for(i = 0; i < count-1; i++)
    {
        for(j = 0; j < count-1; j++)
        {
            if(combine[j] > combine[j+1])     //sorting the combine,fnames,and lnames pointers made in this function
            {
                float temp = combine[j];
                char* ftemp = (char*)malloc(21*sizeof(char));
                char* ltemp = (char*)malloc(21*sizeof(char));
                strcpy(ftemp,fnames[j]);
                strcpy(ltemp,lnames[j]);
                strcpy(fnames[j],fnames[j+1]);
                strcpy(lnames[j],lnames[j+1]);
                strcpy(fnames[j+1],ftemp);
                strcpy(lnames[j+1],ltemp);
                combine[j] = combine[j+1];        //bubble sort for scores
                combine[j+1] = temp;

            }
        }
    }

    count = 0;
    for(i = 0; i < size; i++)       //looping through the original firstNames lastnames and scores in main
    {
        if((*scores)[i] != NULL)
        {
            (*scores)[i][0] = combine[count];
            strcpy((*firstNames)[i],fnames[count]);
            strcpy((*lastNames)[i],lnames[count]);
            count++;
        }
    }
    printer(size,&(*firstNames), &(*lastNames), &(*scores));
    free(combine);
    combine = NULL;
    for(i = 0; i < count; i++)
    {
        free(fnames[i]);
        fnames[i] = NULL;
        free(lnames[i]);
        lnames[i] = NULL;
    }
}

void searchLast(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    int row, count = 0;
    char *name;
    name = (char*)malloc(21*sizeof(char));      //single pointer to store last name we are searching for
    printf("Enter the last name of the user you are searching for: ");
    scanf("%s",name);
    for(row = 0; row < size; row++)
    {
        if((*lastNames)[row] != NULL)           //make sure we don't try to access a spot we free'd
        {
            if(strcmp((*lastNames)[row],name) == 0)
            {
                printf("First Name: %s, Last Name: %s, Score: %f",(*firstNames)[row],(*lastNames)[row],(*scores)[row][0]);
                printf("\n");       //print once found
                count++;
            }
        }
    }
    if(count == 0)
    {
        printf("There is no one with that last name.\n");
    }
    free(name);
    name = NULL;
}

void del(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    char *name;
    int row, count = 0;

    printf("Enter the last name of the user you want to delete records for: ");
    name = (char*)malloc(21*sizeof(char));  //pointer to string of characters
    scanf("%s",name);
    printf("\n\n");
    for(row = 0; row < size; row++)     //loop through the last names double pointer
    {
        if((*lastNames)[row] != NULL)      //if the spot results in null, don't try to compare
        {
            if(strcmp((*lastNames)[row],name) == 0)     //if the spot matches the name the user entered
            {
                free((*firstNames)[row]);               //free everything in the row for that user for every
                free((*lastNames)[row]);                //pointer and set to null
                free((*scores)[row]);
                (*firstNames)[row] = NULL;
                (*lastNames)[row] = NULL;
                (*scores)[row] = NULL;
                count++;
            }
        }
    }
    if(count == 0)
    {
        printf("There is nobody with that last name.\n");
    }
    else
    {
        printer(size, &(*firstNames), &(*lastNames), &(*scores));
    }
    free(name);
    name = NULL;
}

void add(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    *firstNames = realloc(*firstNames,size*sizeof(char*));      //allocates more memory for another row
    *lastNames = realloc(*lastNames,size*sizeof(char*));
    *scores = realloc(*scores,size*sizeof(float*));              //allocates more memory for another float
    (*firstNames)[size-1] = malloc(21*sizeof(char));        //allocates memory for 20 characters in the row
    (*lastNames)[size-1] = malloc(21*sizeof(char));
    (*scores)[size-1] = calloc(1,sizeof(float));

    printf("Please input record of student with following format\n");
    printf("first name last name score\n");
    scanf("%s %s %f",(*firstNames)[size-1],(*lastNames)[size-1],&((*scores)[size-1][0]));
    //takes in input and adds it to the last spot in each pointer
    printer(size, &(*firstNames), &(*lastNames), &(*scores));
}

void allocate(int size, char ***firstNames, char ***lastNames, float ***scores)      //triple pointers because need triple to hold
{                                                                                   //memory addresses of double pointers
    int row, j;

    *firstNames = (char**)malloc(size*sizeof(char*));       //creates the "rows" for double pointers created in main
    *lastNames = (char**)malloc(size*sizeof(char*));
    *scores = (float**)calloc(size,sizeof(float*));           //this works bc the triple pointer points to the double pointer which point
    for(row = 0; row < size; row++)                         //to memory, making this all dynamic
    {
        (*firstNames)[row] = (char*)malloc(21*sizeof(char));
        (*lastNames)[row] = (char*)malloc(21*sizeof(char));
        (*scores)[row] = (float*)calloc(size,sizeof(float));
    }

    for(row = 0; row < size; row++)
    {
        //takes input and the pointers point to it in memory
        scanf("%s %s %f",(*firstNames)[row],(*lastNames)[row],&((*scores)[row][0]));
    }

}

void printer(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    int row;
    for(row = 0; row < size; row++)
    {
        if((*firstNames)[row] != NULL && (*lastNames)[row] != NULL) //if the spot results in null, don't print it
        {
            //print out the values
            printf("First Name: %21s, Last Name: %21s, Score: %10.2f",(*firstNames)[row],(*lastNames)[row],(*scores)[row][0]);
            printf("\n");
        }
    }
}

void functionalities(int size, char ***firstNames, char ***lastNames, float ***scores)
{
    int choices;
    int *s = &size;

    while(choices != 0)     //lets user choose what they wanna do
    {
        printf("\n\nPrint records (press 1)\n");
        printf("Add a new record (press 2)\n");
        printf("Delete record(s) (press 3)\n");
        printf("Search by last name (press 4)\n");
        printf("Sort by score (press 5)\n");
        printf("Sort by last name (press 6)\n");
        printf("Find median score (press 7)\n");
        printf("Exit the program (press 0)\n");
        scanf("%d",&choices);
        printf("\n\n\n");
        if(choices == 1)
            printer(size,&(*firstNames),&(*lastNames),&(*scores));      //functionalities of the program
        else if(choices == 2)
        {
            (*s)++;
            add(size,&(*firstNames),&(*lastNames),&(*scores));
        }
        else if(choices == 3)
        {
            del(size,&(*firstNames),&(*lastNames),&(*scores));
        }
        else if(choices == 4)
        {
            searchLast(size,&(*firstNames),&(*lastNames),&(*scores));
        }
        else if(choices == 5)
        {
            sortScore(size,&(*firstNames),&(*lastNames),&(*scores));
        }
        else if(choices == 6)
        {
            sortLast(size,&(*firstNames),&(*lastNames),&(*scores));
        }
        else if(choices == 7)
        {
            median(size,&(*firstNames),&(*lastNames),&(*scores));
        }
        else if(choices == 0)
        {
            break;
        }
        else
        {
            printf("Not a valid option, try again.\n");
        }
    }
}

int main(void)
{
    int size, choices;
    char **firstNames, **lastNames;     //double pointers to hold the characters for the names
    float ***scores;                      //pointer for the scores
    size = 0;

    while(size < 5)
    {
        printf("Please indicate number of records you want to enter (min 5): ");
        scanf("%d",&size);
        if(size < 5)
        {
            printf("You must have a minimum of 5 records, try again.\n");
        }
    }

    printf("Please input records of students (enter a new line after each record)\n");
    printf("with following format first name last name score\n");
    allocate(size,&firstNames,&lastNames,&scores);      //passing memory addresses so the original pointers are changed
    functionalities(size,&firstNames,&lastNames,&scores);   //that means all parameters will have to be triple pointers

    return 0;
}
