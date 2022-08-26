#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001


void square(double a, double b, double c, int* rootcount, double* x1, double* x2);

void lineal          (double b, double c, int* rootcount, double* x1);

void simple                    (double c, int* rootcount);

void printans                            (int  rootcount, double  x1, double  x2);

void solve (double a, double b, double c, int* rootcount, double* x1, double* x2, int check);

bool equal_double (double num1, double num2);



int main(void) {


    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int rootcount = -1, check = 0;


    printf("Enter the coefficients of the square equation. You can use only numbers.\n");


    check = scanf("%lf %lf %lf", &a, &b, &c);


    solve(a, b, c, &rootcount, &x1, &x2, check);


    printans(rootcount, x1, x2); //function printans print different string depends of how many answers does the equation have


    return 0;
}



void solve(double a, double b, double c, int* rootcount, double* x1, double* x2, int check)  {


if (check == 3) {
    if (equal_double (c,0))

        {

        if (equal_double (b,0)) simple      (c, rootcount);

        else                    lineal   (b, c, rootcount, x1);

        }

    else                        square(a, b, c, rootcount, x1, x2);  //function square solve the equation and return count of answers and their values
    }

}



void lineal(double b, double c, int* rootcount, double* x1)  {

    if (equal_double (c,0)) *x1 =  c/b;

    else                    *x1 = -c/b;

    *rootcount = 1;
}



void square  (double a, double b, double c, int* rootcount, double* x1, double* x2) {


    double d = b*b - 4*a*c;


    if((d - EPSILON) < 0) *rootcount = 0;


    if(equal_double (d,0))
        {
            *rootcount = 1;

            *x1 = (-b) / (2*a);
        }


    if((d - EPSILON) > 0)
        {
            *rootcount = 2;

            *x1 = (-b - sqrt(d)) / (2*a);

            *x2 = (-b + sqrt(d)) / (2*a);
        }
}



void simple(double c, int* rootcount)  {

    if (equal_double (c,0)) *rootcount = 3;   //This equation has an infinite number of roots

    else                    *rootcount = 0;   //This equation has no root
}



void printans(int rootcount, double x1, double x2)  {


    if (rootcount == -1) printf("Error with coefficients, they are not numbers");


    if (rootcount == 0)  printf("The equation has no roots");


    if (rootcount == 1)  printf("The equation has 1 root: x = %.2f", x1);


    if (rootcount == 2)  printf("The equation has 2 roots: x1 = %.2f and x2 = %.2f", x1, x2);


    if (rootcount == 3)  printf("The equation has an infinite number of roots");
}


bool equal_double (double num1, double num2) {

    return fabs (num1 - num2) < EPSILON;
}

