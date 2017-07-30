#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(int *size);
void print();
void functionalities();
void add();
void findLast();
void del(int *spot);
void findZip();
void median(int *size);
void sortScore(float sortedScores[], int *size);

struct student
{
    char firstName[21];
    char lastName[21];
    float score;
    char zip[11]; //10 spots for 9 digits and a dash
    struct student *next;
};
struct student *head;       //head of the linked list
struct student *temp;       //temp used to add and do other various loops through the linked list

void sortScore(float sortedScores[], int *size)     //array is passed by reference so it changes original
{
    int i,j;
    temp = head;
    for(i = 0; i < *size; i++)
    {
        sortedScores[i] = temp->score;      //put the scores from the linked list into the array
        temp = temp->next;
    }
    for(i = 0; i < (*size)-1; i++)
    {
        for(j = 0; j < (*size)-1; j++)
        {
            if(sortedScores[j] > sortedScores[j+1])
            {
                float tempf;
                tempf = sortedScores[j];
                sortedScores[j] = sortedScores[j+1];    //sort the scores in the array
                sortedScores[j+1] = tempf;
            }
        }
    }
}

void median(int *size)
{
    float sortedScores[*size];
    sortScore(sortedScores,&(*size));   //fill scores array and sort it
    if((*size) % 2 == 0)                //determine median using arrays created from the linked list
    {
        int med1;
        int med2;
        med1 = ((*size)/2)-1;       //finding median if size is even
        med2 = (*size)/2;
        float average;
        average = (sortedScores[med1] + sortedScores[med2])/2;
        printf("The median score is %.2f. There are %d students above this score.\n",average,(*size)/2);
    }
    else
    {
        int mid;
        mid = (*size)/2;    //finding median if size is odd
        float med;
        med = sortedScores[mid];
        printf("The median score is %.2f. There are %d students above this score.\n",med,mid);
    }
}

void findScores()
{
    int count, r;
    float min, max;
    r = 0;
    while(r == 0)
    {
        printf("Enter the min score for the range of scores you are looking for: ");
        scanf("%f",&min);
        printf("Enter the max score for the range of scores you are looking for: ");
        scanf("%f",&max);
        if(max < min)
        {
            printf("Error: Max is less than min. Try again.\n\n");
        }
        else
        {
            r = -1;
        }
    }
    printf("\n\n");
    temp = head;
    count = 0;
    while(temp != NULL)
    {
        if(temp->score <= max && temp->score >= min)    //if the score is in the range, print records
        {
            printf("First Name: %s, Last Name: %s, Score: %.2f Zip code: %s \n",temp->firstName,temp->lastName,temp->score,temp->zip);
            count++;
        }
        temp = temp->next;
    }
    if(count == 0)
    {
        printf("No scores in that range could be found.\n");
    }
}

void findZip()
{
    char zipf[11];  //store zip code the user is looking for
    int count;
    count = 0;
    printf("Enter the zip code you are looking for: ");
    scanf("%s",zipf);
    printf("\n");
    temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->zip,zipf) == 0) //if zipcode user entered matches one in the linked list, print it
        {
            printf("First Name: %s, Last Name: %s, Score: %.2f Zip code: %s \n",temp->firstName,temp->lastName,temp->score,temp->zip);
            count++;
        }
        temp = temp->next;
    }
    if(count == 0)
    {
        printf("That zip code could not be found.\n");
    }
}

void del(int *spot)
{
    int count;
    count = 0;
    struct student *temp2;
    struct student *del;
    del = head;     //spot here is just the spot that will be deleted
    temp2 = head;
    while(temp != NULL)
    {
        if(*spot == 0)      //if user is deleting something in the first spot
        {                   //need this specific case bc the other would cause errors
            del = head;
            head = del->next;
            free(del);
            break;
        }
        else if(*spot != 0 && count == (*spot)-1)   //if user is deleting anything else
        {
            del = temp2->next;
            temp2->next = del->next;
            free(del);
            break;
        }
        temp2 = temp2->next;
        count++;    //count keeps track of where we are in the linked list
    }
}


void findLast(int *size)
{
    int spot, count;
    spot = 0;
    count = 0;
    temp = head;
    char name[21];  //store last name of user that needs to be deleted
    printf("Enter the last name of the user you want to delete: ");
    scanf("%s",name);
    printf("\n\n");
    while(temp != NULL)
    {
        if(strcmp(temp->lastName,name) == 0)    //if the last name the user entered matches one in the linked list
        {                                       //pass del spot, spot will have the position inside the linked list
            del(&spot);                         //of the name that needs to be deleted
            count++;
            spot--;                             //after deletion, decrease spot because the index has changed since size is now
            (*size)--;                          //one less
        }                                       //in short, everytime a name is matched, it goes to del and loops through again
        temp = temp->next;                      //to delete. looping again is needed bc it is a linked list.
        spot++;             //moving onto the next spot in the linked list
    }
    if(count == 0)
    {
        printf("That last name could not be found.\n\n\n");
    }
    else
    {
        print();
    }
}


void add()
{
    if(head != NULL)
    {
        temp = head;
        while(temp->next != NULL)       //go to the end of the linked list and add a "node" for another student
        {
            temp = temp->next;
        }
        temp->next = (struct student*)malloc(sizeof(struct student));
        temp = temp->next;
        temp->next = NULL;  //make pointer null to indicate end of linked list
    }
    else //need a specific case for if the list is empty (head is null)
    {
        temp = (struct student*)malloc(sizeof(struct student));
        head = temp;
    }
    printf("Please input record of student with following format:\n");
    printf("first name last name score zip code\n\n");
    scanf("%s %s %f %s",temp->firstName,temp->lastName,&(temp->score),temp->zip);       //taking in input
    printf("\n");
    print();
}

void create(int *size)
{
    int i;
    temp = (struct student*)malloc(sizeof(struct student));     //initial creation of first node
    head = temp;
    for(i = 1; i < *size; i++)
    {
        temp->next = (struct student*)malloc(sizeof(struct student));   //creation of other nodes if user wanted > 1
        temp = temp->next;
    }
    temp->next = NULL;
}

void print()
{
    temp = head;
    while(temp != NULL)
    {
        printf("First Name: %s, Last Name: %s, Score: %.2f Zip code: %s \n",temp->firstName,temp->lastName,temp->score,temp->zip);
        temp = temp->next;      //print
    }
}

void functionalities()
{
    int size, ch, i;
    printf("Please indicate number of records you want to enter (min 5): ");
    scanf("%d",&size);

    while(size < 5)
    {
        printf("The minimum number of records is 5, try again.\n\n");
        printf("Please indicate number of records you want to enter (min 5): ");
        scanf("%d",&size);
    }

    create(&size);      //create linked list with size user entered (number of nodes is size)
    ch = 0;

    printf("Please input records of students (enter a new line after each record), with following format:\n");
    printf("first name last name score zip code\n\n");
    temp = head;
    while(temp != NULL)
    {
        scanf("%s %s %f %s",temp->firstName,temp->lastName,&(temp->score),temp->zip);   //taking in input for each node
        temp = temp->next;
    }
    while(ch != -1)
    {
        printf("\nPrint records (press 1)\n");      //functionalities provided to the user
        printf("Add a new record (press 2)\n");
        printf("Delete record(s) (press 3)\n");
        printf("Search by zip code (press 4)\n");
        printf("Search by score range (press 5)\n");
        printf("Find median score (press 6)\n");
        printf("Exit the program (press 0)\n");
        scanf("%d",&ch);
        printf("\n\n");
        if(ch == 1)
        {
            print();
        }
        else if(ch == 2)
        {
            add();
            size++;     //increase size since something is added
        }
        else if(ch == 3)
        {
            findLast(&size);    //this is the delete function but separated into a findLast and another func just for deleting
        }                       //pass size as a memory address so original is changed
        else if(ch == 4)
        {
            findZip();
        }
        else if(ch == 5)
        {
            findScores();
        }
        else if(ch == 6)
        {
            median(&size);
        }
        else if(ch == 0)
        {
            break;
        }
        else
        {
            printf("That is not a valid option, try again.\n");
        }
    }
}

int main(void)
{
    functionalities();
    return 0;
}
