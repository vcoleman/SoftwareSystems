/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{
    if (n >= strlen(s)){}
        char *joinedStr;
        joinedStr = (char *)malloc(n);
        
        int i;
        char firstFill;
        firstFill = (int)((n - strlen(s)) /2 );
        for (i = 0; i < firstFill; i++){
            strcat(joinedStr, fillchar[0]);
        }
        for (i = 0; i <=strlen(s); i ++){
            strcat(joinedStr, s[i]);
        }
        for (i = strlen(joinedStr); i < n; i++){
            strcat(joinedStr, fillchar[0]);
        }
        return joinedStr;
    } 
return s
}


int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
