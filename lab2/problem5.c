#include <stdio.h>

void reverse(char word[], int size)
{
    int i;
    for(i = size; i > -1; i--)
    {
        printf("%c",word[i]);       //print it out backwards by starting at the end of the string
    }
    printf("\n");
}

void main(void)
{
    int size;
    char word[10000]; //limit is 10000, anything under 10000 will work
    printf("Enter a string: ");
    scanf("%[^\n]",&word);  //takes input up until the user presses enter
    size = strlen(word);    //size is size of the string including \0 so it can be printed without the leftover junk
    reverse(word, size);
}
