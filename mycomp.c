/* interface with the user
 * read and response to the input
 * define of the 6 variables */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"


int main()
{
    int lengthTemp = 0, newTempLength;
    char input[MAX_LINE_LENGTH];
    char *outputString = (char *)malloc((MAX_LINE_LENGTH + 1) * sizeof(char));
    char returnString[300];

    initializeCompList(compList);
    if (outputString == NULL)
    {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }

    printf("Enter a command:\n");

    while (1)
    {
        /*get the current line to play the command ends with \n */

        if (fgets(input, MAX_LINE_LENGTH, stdin) == NULL) /*ending ungracefully with EOF*/
        {
            printf("%s\b\bError - ending with EOF instead of 'stop' command\n", outputString);
            free(outputString);
            return 0;
        }
        if (input[strlen(input) - 1] == EOF) /* Ending ungracefully with EOF and have a command beofre*/
        {
            printf("%s\nError - ending with EOF instead of 'stop' command\n\n", outputString);
            free(outputString);
            return 0;
        }
        if (strcmp(input, "stop\n") == 0 || strcmp(input, "stop") == 0) /*ending gracefullt with stop\n or stop*/
        {
            printf("%s", outputString);
            free(outputString);
            return 0;
        }

        removeWhitespace(input);

        strcpy(returnString, isValidInput(input));
        /* Append the input to the outputString*/
        lengthTemp = strlen(outputString);
        newTempLength = lengthTemp + strlen(input) + 10 + strlen(returnString); /* command length + error msg+ the new commad*/
        outputString = (char *)realloc(outputString, newTempLength * sizeof(char));
        if (outputString == NULL)
        {
            printf("Memory reallocation failed. Exiting...");
            free(outputString);
            return 1;
        }

        strcat(outputString, input);
        strcat(outputString, ": ");
        strcat(outputString, returnString);
    }
    return 0;
}

void initializeCompList(complex compList[])
{
    complex A = {0.0, 0.0};
    complex B = {0.0, 0.0};
    complex C = {0.0, 0.0};
    complex D = {0.0, 0.0};
    complex E = {0.0, 0.0};
    complex F = {0.0, 0.0};
    complex SUM = {0.0, 0.0};

    compList[0] = A;
    compList[1] = B;
    compList[2] = C;
    compList[3] = D;
    compList[4] = E;
    compList[5] = F;
    compList[6] = SUM;
}
