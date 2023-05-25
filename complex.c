/* all the arithmetic actions */
#include <stdio.h>
#include <math.h>
#include "complex.h"

extern char calcResult[];

const char *read_comp(char c1, double a, double b)
{ /*c = a + bi*/
    int i = c1 - 65;
    compList[i].a = a;
    compList[i].b = b;
    return "\n";
}
const char *print_comp(char c)
{ /* 5.10 + (6.23)i*/
    int i = c - 65;
    sprintf(calcResult, "%f+(%f)i\n", compList[i].a, compList[i].b);
    return calcResult;
}
const char *add_comp(char c1, char c2)
{ /* (a + bi ) + ( c + di ) = ( a + c ) + ( b + d )i*/
    int i = c1 - 65;
    int j = c2 - 65;
    compList[6].a = compList[i].a + compList[j].a;
    compList[6].b = compList[i].b + compList[j].b;
    return (print_comp(71));
}
const char *sub_comp(char c1, char c2)
{ /* (a + bi ) – ( c + di ) = ( a – c ) + ( b – d )i*/
    int i = c1 - 65;
    int j = c2 - 65;
    compList[6].a = compList[i].a - compList[j].a;
    compList[6].b = compList[i].b - compList[j].b;
    return (print_comp(71));
}
const char *mult_comp_real(char c1, double x)
{ /* m ( a + bi ) =ma + (mb)i*/
    int i = c1 - 65;
    compList[6].a = compList[i].a * x;
    compList[6].b = compList[i].b * x;
    return (print_comp(71));
}
const char *mult_comp_img(char c1, double x)
{ /* mi (a + bi ) = –mb + (ma)i*/
    int i = c1 - 65;
    compList[6].a = compList[i].b * x * (-1);
    compList[6].b = compList[i].a * x;
    return (print_comp(71));
}
const char *mult_comp_comp(char c1, char c2)
{ /*(a + bi ) ( c + di ) = (ac – bd ) + ( ad + bc )i*/
    int i = c1 - 65;
    int j = c2 - 65;
    compList[6].a = (compList[i].a * compList[j].a) - (compList[i].b * compList[j].b);
    compList[6].b = (compList[i].a * compList[j].b) + (compList[i].b * compList[j].a);
    return (print_comp(71));
}
const char *abs_comp(char c1)
{ /*|𝑎 + 𝑏𝑖| = V(a^2+b^2)*/
    int i = c1 - 65;
    compList[6].a = sqrt(pow(compList[i].a, 2.0) + pow(compList[i].b, 2.0));
    sprintf(calcResult, "%f\n", compList[6].a);
    return calcResult;
}
const char *stop()
{
    return "0";
}
