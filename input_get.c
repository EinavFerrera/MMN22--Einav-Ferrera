#include <stdio.h>
#include "complex.h"

void removeWhitespace(char *str)
{
    int i, j = 0;
    int spaceCount = 0;

    for (i = 0; str[i] != '\n'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            spaceCount++;
        }
        else
        {
            if (spaceCount > 0)
            {
                str[j++] = ' ';
                spaceCount = 0;
            }
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}
void removeAllspace(char *str)
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
