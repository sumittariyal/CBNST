#include<stdio.h>
#include<math.h>
float f(float x)
{
    return ((x*x*x)-5*x+1);
}
int main()
{
    printf("Equation is x^3 - 5^x +1\n");
    float x1,x0,x;
    while(1)
    {
        printf("Enter the intital guess(x0) & (x1):");
        scanf("%f%f",&x0,&x1);
        if(f(x0)*f(x1) < 0)
        {
            printf("Root lies between %f and %f\n",x0,x1);
            break;
        }
        else{
            printf("try again\n");
        }
    }
    float aerr;
    printf("Enter the accuracy\n");
    scanf("%f",&aerr);
    int itr = 0;
    float fx1,fx0;
    while(1)
    {
        itr++;
        fx0 = f(x0);
        fx1 = f(x1);
        x = x1-((x1-x0)/(fx1-fx0))*fx1;
        printf("%d iteration | value of x%d is %f\n ",itr,itr,x);
        if(fabs(f(x))<= aerr)
        {
            printf("Root found in %d iteration and valu e of x is %f",itr,x);
            break;
        }
     x0 = x1;
     x1 = x;

    }
}