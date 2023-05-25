
#ifndef COMPLEX_H
#define COMPLEX_H

// what?
// this is sec
#define MAX_LINE_LENGTH 100

typedef struct
{
    double a;
    double b;
} complex;

complex compList[7];
char calcResult[MAX_LINE_LENGTH];

/*mycomp.c*/
void initializeCompList(complex[]);

/*input_get*/
void removeWhitespace(char *str);
void removeAllspace(char *str);

/*input_check.c*/
const char *isValidInput(const char *input);
const char *errorCheck(const char[], int, int, int, int);
int charCheck(char);

/*complex.c*/
const char *read_comp(char, double, double);
const char *print_comp(char);             /* 5.10 + (6.23)i*/
const char *add_comp(char, char);         /* (a + bi ) + ( c + di ) = ( a + c ) + ( b + d )i*/
const char *sub_comp(char, char);         /* (a + bi ) – ( c + di ) = ( a – c ) + ( b – d )i*/
const char *mult_comp_real(char, double); /* m ( a + bi ) =ma + (mb)i*/
const char *mult_comp_img(char, double);  /* mi (a + bi ) = –mb + (ma)i*/
const char *mult_comp_comp(char, char);   /*(a + bi ) ( c + di ) = (ac – bd ) + ( ad + bc )i*/
const char *abs_comp(char);               /*|𝑎 + 𝑏𝑖| = V(a^2+b^2)*/
const char *stop();

#endif
