#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int tolower(int c);
void comparsion(char a[], char b[])
{
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i]>=97 && a[i]<=122)
        {
            for(int j=0; j<strlen(b); j++)
            {
                if(a[i]==b[j])
                {
                    a[i]=' ';
                    b[j]=' ';
                }
            }
        }
    }
}
int check(char a[], char b[])
{
    for(int i=0; i<strlen(a)-1; i++)
    {
        if(a[i]!=' ' || b[i]!=' ')
        {
            return 0;
        }
    }
    return 1;
}
void remove_blanks(char a[], char b[])
{
    int c=0, d=0;
    while (a[c] != '\0')
    {
        if (!(a[c] == ' ' || a[c] == 9))
        {
            b[d] = a[c];
            d++;
        }
        c++;
    }
   b[d]='\0';
}
int main()
{
    int max_l=50;
    char first[max_l], second[max_l], first_no_blanks[max_l], second_no_blanks[max_l];
    printf("Enter first string:");
    fgets(first, max_l, stdin);
    printf("Enter second string:");
    fgets(second, max_l, stdin);
    for(int i=0; i<50; i++)
    {
        first[i]=tolower(first[i]);
        second[i]=tolower(second[i]);
    }
    remove_blanks(first, first_no_blanks);
    remove_blanks(second, second_no_blanks);
    comparsion(first_no_blanks,second_no_blanks);
    if(check(first_no_blanks, second_no_blanks)==1)
    {
        printf("Entered strings are anagrams.\n");
    }
    else
    {
        printf("Entered strings aren't anagrams.\n");
    }
    system("pause");
    return 0;
}