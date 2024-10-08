#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (x*log(x)-1.2);
}
int main()
{
float x,x1,x2,aerr;
int fg = 0,itr = 0;
printf("Equation : x* log(x)-1.2\n");
do{
    printf("Enter the value of x1 & x2 :");
    scanf("%f%f",&x1,&x2);
    if(f(x1)*f(x2)< 0)
    {
     fg = 1;
     printf("Roots lie between %f and %f\n",x1,x2);
    }
    else{
        printf("No root exists in the given interval\n");
    }
}while(fg == 0);
printf("Enter the accuracy :");
scanf("%f",&aerr);
while(fg == 1)
{
  x = (x1 + x2)/2;
  itr++;
  printf("%d iteration value of x is %f,value of(%f) is %f\n",itr,x,x,f(x) );
  if(fabs(f(x))<= aerr || fabs(x2-x1) <= aerr)
  {
      fg = 0;
      printf("\n\nRoot found at x = %f in %d iterations",x,itr);
  }
  else if(f(x) * f(x1) < 0)
  {
    x2 = x;
  }
  else{
    x1 = x;
  }
}


}