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


int check_phrase_contained(
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


int iterate_over_input_array(
    char **argv, int n
)
{
    int i = 0;
    char *element;
    for (i = 0; i < n; i++)
    {
        element = argv[i];
        printf("Element %d is : %s\n", i, element);
    }
}

int *filter_array(
    char **raw_array,
    char **filtering_entries,
    int dim_raw,
    int dim_filter
)
{
    char *result = malloc(dim_filter);
    char *phrase;
    if (!result)
        return NULL;
    for (int i = 0; i < dim_raw; ++i)
    {
        phrase = raw_array[i];
        result[i] = check_phrase_contained(
            phrase,
            filtering_entries,
            dim_filter
        );
    }
    return result;
}

int main() 
{
    /*
    char *string1 = "A first string";
    char *string2 = "A second string";
    printf(
        "string 1 is %s and string 2 is %s -> %d\n",
        string1,
        string2,
        compare_strings(string1, string2)
    );
    printf(
        "string 1 is %s and string 2 is %s -> %d\n",
        string1,
        string1,
        compare_strings(string1, string1)
    );
    */

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

    // For a set of 10 sentences of length 10
    char *some_sentences[10];
    char buffer[10];
    for (int i = 0; i < 10; ++i)
    {
        snprintf(buffer, sizeof(buffer), "sentence %i", i);
        some_sentences[i] = buffer;
    }
    // Let us filter which ones are included in
    char *filter[3];
    filter[0] = "sentence 9";
    filter[1] = "sentence 1";
    filter[2] = "sentence 2";

    int filtered[10];
    filtered = filter_array(some_sentences, filter, 10, 3);



    return 0;
}