// Newton forward interpolation
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number of values\n");
    scanf("%d",&n);
   float a[n][n+1];
    printf("Enter the value of x\t :");
    for(int i = 0;i < n;i++)
    {
        scanf("%f",&a[i][0]);
    }
    printf("Enter the value of y\t :");
    for(int i = 0;i < n;i++)
    {
        scanf("%f",&a[i][1]);
    }
    float x;
    printf("Enter the value of x for which you want y :");
    scanf("%f",&x);
    for(int j = 2; j <=n;j++)
    {
        for(int i = 0;i < n-j+1;i++)
        {

           a[i][j]=a[i+1][j-1]-a[i][j-1];
        }
    }
    for(int i = 0;i  < n;i++)
    {
        for(int j = 0;j <= n-i;j++)
        {
            printf("%f\t",a[i][j]);
        }
        printf("\n");
    }
    float u = (x-a[0][0])/(a[1][0]-a[0][0]);
    float y = a[0][1];
    int fact = 1;
    float u1 = u;
    for(int i = 2;i <= n;i++)
    {
        y = y + (u1 * a[0][i])/fact;
        fact = fact*i;
        u1 = u1 * (u - (i-1));
    }
    printf("\n Result is  %f",y);
}