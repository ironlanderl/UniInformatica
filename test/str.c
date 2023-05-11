#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char s1[] = "Test";
    char *s2 = malloc(sizeof(s1));
    char *s3 = malloc(sizeof(s1));

    strcpy(s2, s1);
    printf(s2);

    memcpy(s3, s1, sizeof(s1));
    printf(s3);

    free(s2);free(s3);

    return 0;
}
