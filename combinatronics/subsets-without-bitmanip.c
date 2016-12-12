#include <stdio.h>
#include <malloc.h>
#include <string.h>

void subsequences(char* prefix, int prefixLength, const char* suffix)
{
    if (prefixLength >= 1)
        printf("%s\n", prefix);

    for (size_t i=0; i < strlen(suffix); ++i) 
    {
        prefix[prefixLength] = suffix[i];
        prefix[prefixLength + 1] = '\0';
        subsequences(prefix, prefixLength + 1, suffix + i + 1);
    }
}

int main()
{
    const char *inputString = "12345";
    char *prefix = (char*) malloc(strlen(inputString) + 1);
    subsequences(prefix, 0, inputString);
}