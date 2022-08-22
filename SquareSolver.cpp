#include <stdio.h>
#include <TXLib.h>
int main(void)
{
    float a,b,c,d,x1,x2;
    printf("Enter the coefficients of the square equation.\n");
    scanf("%f %f %f",&a,&b,&c);
    if(a==0)
        printf("Cringe with coefficients");
    else
    {
        d=b*b - 4*a*c;
        if(d<0)
            printf("Cringe with discriminant");
        else
            {
                if(d==0)
                    {
                        x1=(-b)/2*a;
                        printf("The solution of the equation is %.2f",x1);
                    }
                else
                    {
                        x1=(-b-sqrt(d))/(2*a);
                        x2=(-b+sqrt(d))/(2*a);
                        printf("The solutions of the equation are  %.2f and %.2f",x1,x2);
                    }
            }
    }
    return(0);
}
