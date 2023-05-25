#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "complex.h"

const char *isValidInput(const char *input)
{
    int i;
    int validFunction = 0;
    int argu1 = -2, argu2 = -2, argu3 = -2, argu4 = -2;
    char c1[30], c2[30], c3[30], c4[30];
    char ch1, ch2;
    double d1, d2, d3;
    /* Function names and their corresponding formats*/
    const char *functionNames[] = {
        "read_comp",
        "print_comp",
        "add_comp",
        "sub_comp",
        "mult_comp_real",
        "mult_comp_img",
        "mult_comp_comp",
        "abs_comp",
        "stop"};

    const char *functionFormats[] = {
        "%[^,],%[^,], %[^\n]",
        "%[^\n]",
        "%[^,],%[^\n]",
        "%[^,],%[^\n]",
        "%[^,],%[^\n]",
        "%[^,],%[^\n]",
        "%[^,],%[^\n]",
        "%[^\n]",
        "%[^\n]"};

    char functionName[100]={' '};
    char params[100];
    
     
    /* checks if the string is only whitespaces */
    sscanf(input, "%s", functionName);
    removeAllspace(functionName);
    if (functionName[0] == '\0')
    	return "\b\b";
    
    /* Extract function name and parameters from input*/
    sscanf(input, "%s %[^\n]", functionName, params);
    removeAllspace(params);
   

     /*Check if the function name is valid*/
    for (i = 0; i < 8; i++)
    {
        if (strcmp(functionName, functionNames[i]) == 0)
        {
            validFunction = 1;
            break;
        }
    }

    if (!validFunction)
    {
        return errorCheck(functionName, 10, 10, 10, 10);
    }
    /*Check if the parameters match the expected format*/

    switch (i)
    {
    case 0: /*read_comp A,3.2,4.8*/
        sscanf(params, functionFormats[i], c1, c2, c3);
        argu1 = sscanf(c1, "%c", &ch1);
        argu2 = sscanf(c2, "%lf", &d1);
        argu3 = sscanf(c3, "%lf", &d2);
        argu4 = sscanf(c3, "%lf %s", &d3, c4);
        argu1 = charCheck(ch1); /* checks if ch1 is A-F*/

        if ((argu1 + argu2 + argu3 != 3) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return read_comp(ch1, d1, d2);

        break;

    case 1: /*print_comp A*/
        sscanf(params, functionFormats[i], c1);
        argu1 = sscanf(c1, "%c", &ch1);
        argu4 = sscanf(c1, "%c %29s", c4, c4);
        argu1 = charCheck(ch1); /* checks if ch1 is A-F*/

        if ((argu1 != 1) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return print_comp(ch1);
        break;

    case 2: /*add_comp A,B*/
        sscanf(params, functionFormats[i], c1, c2);
        argu1 = sscanf(c1, "%c", &ch1);
        argu2 = sscanf(c2, "%c", &ch2);
        argu4 = sscanf(c2, "%c %29s", c4, c4);
        argu1 = charCheck(ch1); /* checks if ch1 is A-F*/
        argu2 = charCheck(ch2); /* checks if ch2 is A-F*/

        if ((argu1 + argu2 != 2) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return add_comp(ch1, ch2);
        break;

    case 3: /*sub_comp A,B*/
        sscanf(params, functionFormats[i], c1, c2);
        argu1 = sscanf(c1, "%c", &ch1);
        argu2 = sscanf(c2, "%c", &ch2);
        argu4 = sscanf(c2, "%c %29s", c4, c4);
        argu1 = charCheck(ch1); /* checks if ch1 is A-F*/
        argu2 = charCheck(ch2); /* checks if ch2 is A-F*/

        if ((argu1 + argu2 != 2) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return sub_comp(ch1, ch2);
        break;

    case 4: /*mult_comp_real A,3.2*/
        sscanf(params, functionFormats[i], c1, c2);
        argu1 = sscanf(c1, "%c", &ch1);
        argu2 = sscanf(c2, "%lf", &d1);
        argu4 = sscanf(c2, "%lf %29s", &d3, c4);
        argu1 = charCheck(ch1); /* checks if ch1 is A-F*/

        if ((argu1 + argu2 != 2) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return mult_comp_real(ch1, d1);
        break;

    case 5: /*mult_comp_img*/
        sscanf(params, functionFormats[i], c1, c2);
        argu1 = sscanf(c1, "%c", &ch1);
        argu2 = sscanf(c2, "%lf", &d1);
        argu4 = sscanf(c2, "%lf %29s", &d3, c4);
        if ((argu1 + argu2 != 2) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return mult_comp_img(ch1, d1);
        break;

    case 6: /*mult_comp_comp A,B*/
        sscanf(params, functionFormats[i], c1, c2);
        argu1 = sscanf(c1, "%c", &ch1);
        argu2 = sscanf(c2, "%c", &ch2);
        argu4 = sscanf(c2, "%c %29s", c4, c4);
        argu1 = charCheck(ch1); /* checks if ch1 is A-F*/
        argu2 = charCheck(ch2); /* checks if ch2 is A-F*/

        if ((argu1 + argu2 != 2) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return mult_comp_comp(ch1, ch2);
        break;

    case 7: /*abs_comp*/
        sscanf(params, functionFormats[i], c1, c2);
        argu1 = sscanf(c1, "%c", &ch1);
        argu4 = sscanf(c1, "%c %29s", c4, c4);
        argu1 = charCheck(ch1); /* checks if ch1 is A-F*/

        if ((argu1 != 1) || argu4 == 2)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        return abs_comp(ch1);
        break;
    case 8: /*stop*/
        sscanf(params, functionFormats[i], &c1);
        argu1 = sscanf(c1, "%29s", c1);
        if (argu1 == 0)
        {
            return errorCheck(functionNames[i], argu1, argu2, argu3, argu4);
            break;
        }
        stop();
        break;
    }
    return "NULL";
}

const char *errorCheck(const char func[], int arg1, int arg2, int arg3, int arg4)
{
    
    if (arg1 + arg2 + arg3 + arg4 == 40) /*unknow function name = 10,10,10,10*/
    {
        return "Error - Unknow function name\n";
    }
    if (arg1 == 8 || arg2 == 8 || arg3 == 8) /*char ','*/
    {
        return "Error - Illegal comma\n";
    }
    if (arg1 == 5 || arg2 == 5) /*chars are not A-F*/
    {
        return "Error - Undefined complex variable\n";
    }
    if (!strcmp(func, "read_comp"))
    {
        if (arg1 != 1) /*arg1 != 1 - not char*/
            return "Error - First parameter should be a character A-F\n";
        if (arg2 != 1) /*arg2!= 1 - not double*/
            return "Error - Second parameter, after the comma, should be a Number\n";
        if (arg3 != 1) /*arg3!= 1 - not double*/
            return "Error - Third parameter, after the comma, should be a Number\n";
        if (arg4 == 2) /*arg4 == 1 - extra text after end*/
            return "Error - no charcters allowed after end of command\n";
    }
    if (!(strcmp(func, "add_comp") && strcmp(func, "sub_comp") && strcmp(func, "mult_comp_comp")))
    {
        if (arg1 != 1) /*arg1 != 1 - not char*/
            return "Error - First parameter should be a character A-F\n";
        if (arg2 != 1) /*arg2!= 1 - not char*/
            return "Error - Second parameter, after the comma, should be a character A-F\n";
        if (arg4 == 2) /*arg4 == 1 - extra text after end*/
            return "Error - no charcters allowed after end of command\n";
    }
    if (!(strcmp(func, "mult_comp_real") && strcmp(func, "mult_comp_img\n")))
    {
        if (arg1 != 1) /*arg1 != 1 - not char*/
            return "Error - First parameter should be a character A-F\n";
        if (arg2 != 1) /*arg2 != 1 - not double*/
            return "Error - Second parameter, after the comma, should be a Number\n";
        if (arg4 == 2) /*arg4 == 1 - extra text after end*/
            return "Error - no charcters allowed after end of command\n";
    }
    if (!(strcmp(func, "print_comp") && strcmp(func, "abs_comp")))
    {
        if (arg1 != 1) /*arg1 != 1 - not char*/
            return "Error - First parameter should be a character A-F\n";
        if (arg4 == 2) /*arg4 == 1 - extra text after end*/
            return "Error - no charcters allowed after end of command\n";
    }
    return "ErrorCheck - invalid\n";
}

int charCheck(char c)
{
    if (c >= 'A' && c <= 'F')
        return 1;
    else if (c == ',')
        return 8;

    else
        return 5;
}
