#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (x*x-12);
}
float df(float x)
{
    return x*x*x/3;
}
int main()
{
 printf("Equation is x^2-12\n");
 float x0,x1,fg=0,aerr;
 do{
    printf("Enter the initial guess(x0) and (x1)\n");
    scanf("%f%f",&x0,&x1);
    if(f(x0)*f(x1) < 0)
    {
        printf("Root lies between %f and %f\n",x0,x1);
        fg = 1;
    }
 }while(fg == 0);
 printf("Enter the accuracy\n");
 scanf("%f",&aerr);
 x0 = (x0 + x1)/2;
 int itr=0;
 float x;
 while(1)
 {
    itr++;
    float fx = f(x0);
    float dfx = df(x0);
    x = x0-fx/dfx;
    printf("%d itertaion value of x%d is %f\n",itr,itr,x);
    if(fabs(x-x0)<= aerr)
    {
       printf("Root for the given equation is %f found in %d iteration ",x,itr);
       break;
    }
x0 = x;
 }
}