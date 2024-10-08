#include<stdio.h>
#include<math.h>
int main()
{
  int size;
  printf("Enter the size of matrix\n");
  scanf("%d",&size);
  float arr[size][size+1];
  printf("Enter the values in augmented matrix\n");
  for(int i= 0;i < size;i++)
  {
    for(int j = 0;j <= size;j++)
    {
       scanf("%f",&arr[i][j]);
    }
  }
  printf("Your entered matrix is :\n");
  for(int i = 0;i < size;i++)
  {
    for(int j =0;j <= size;j++)
    {
     printf("%.2f\t",arr[i][j]);
    }
    printf("\n");
  }

for(int i = 0;i < size;i++)
{
    for(int j = 0; j < size;j++)
    {
        if(i != j){
        float factor = arr[j][i]/arr[i][i];
        for(int k = 0; k <= size;k++)
        {
          arr[j][k]-= factor*arr[i][k];
        }
        }
    }
}
printf("Diagonal matrix is :\n");
for(int i = 0;i < size;i++)
{
    for(int j = 0;j <= size;j++)
    {
        printf("%.2f\t",arr[i][j]);
    }
    printf("\n");
}
float solution[size];
for(int i = 0;i < size;i++)
{
    solution[i]=arr[i][size]/arr[i][i];
}
printf("Solution is :\n");
for(int i = 0;i < size;i++)
{
    printf("X%d = %.2f\n",i+1,solution[i]);
}
}