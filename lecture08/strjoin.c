/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *tracks[] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/* Returns a heap-allocated string that contains the strings 
   from the given array, joined up with no spaces between.
*/
char *strjoin(char *array[], int n)
{
    int i;
    int length = 0;

    for (i = 0; i < n; i++){
        length += strlen(array[i]);
    }

    char *joinedStr;
    //allocate space in heap for string of total size
    joinedStr = (char *)malloc(sizeof(char)*length);

    for (i = 0; i < n; i++){
        strcat(joinedStr, array[i]);
    }

    return joinedStr;
}


int main (int argc, char *argv[])
{
    char *s = strjoin(tracks, 5);
    printf("%s\n", s);
    return 0;
}
