#include<stdio.h>
#include<math.h>
float f(float x)
{
    return fabs(cosf(x)-(3*x)+1);
}
float g(float x)
{
    return fabs((cosf(x)+1)/3);
}
float dg(float x)
{
    return fabs(sinf(x)/3);
}
int main()
{
    float x0,x;
    printf("Equation is cosx -3x +1\n");
    while(1)
    {
    printf("Enter the value of x0 :");
    scanf("%f",&x0);
    if(dg(x0) < 1)
    {
        printf("You can Proceed\n");
        break;
    }
    printf("Try again");
 }
 x0 = g(x0);
 float aerr ;
 printf("Enter the allowed error\n");
 scanf("%f",&aerr);
 int itr = 0;
 while(1)
 {
    itr++;
    printf("%d iteration | value of x0 is %f | value of f(x0) is %f\n",itr,x0,f(x0));
    if(f(x0) <= aerr)
    {
        printf("Root found in the %d iteration and root is %f\n",itr,x0);
        break;
    }
    x0 = g(x0);

 }

}