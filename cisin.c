#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(char *string1, char *string2) 
{
    int result;
    
    result = strcmp(string1, string2);
    
    if (result == 0)
    {
        return 1;
    } 
    else 
    {
        return 0;   
    }
}


int c_isin(
    char *input_phrase,
    char **list_of_phrases,
    int dimmax
)
{
    int contained = 0;
    int i = 0;
    int end_loop = 0;
    int check_equal;

    while (i < dimmax) 
    {
        check_equal = compare_strings(input_phrase, list_of_phrases[i]);
        if (check_equal == 1) 
        {
            contained = 1;
            break;
        }
        i++;
    }
    return contained;
}


/*
int main() 
{

//    char *string1 = "A first string";
//    char *string2 = "A second string";
//    printf(
//        "string 1 is %s and string 2 is %s -> %d\n",
//        string1,
//        string2,
//        compare_strings(string1, string2)
//    );
//    printf(
//        "string 1 is %s and string 2 is %s -> %d\n",
//        string1,
//        string1,
//        compare_strings(string1, string1)
//    );

    int comparison;
    int dimmax = 4;
    char *strarray[5];
    strarray[0] = "A first sentence";
    strarray[1] = "A second sentence";
    strarray[2] = "A third senence";
    strarray[3] = "A fourth sentence";
    strarray[4] = "A fifth sentence";

    char *phrase;
    int is_contained;
    phrase = "A first sentence";
    is_contained = check_phrase_contained(phrase, strarray, dimmax);
    printf("Phrase %s is contained in set -> %d\n", phrase, is_contained);

    return 0;
}*/