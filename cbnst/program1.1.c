
#include<stdio.h>
#include<math.h>
float absoluteErr( float trueVal , float approxVal ) {
float ans = trueVal - approxVal ;
return fabs(ans) ;
}
float relativeErr( float trueVal , float approxVal ) {
float ans = (trueVal - approxVal) / trueVal ;
return fabs(ans) ;
}
float percentageErr( float trueVal , float approxVal ) {
float ans = relativeErr(trueVal, approxVal) * 100 ;
return fabs(ans) ;
}
int main()
{
float trueValue = sqrt(2) , approximateValue ;
printf("True Value : %f\n",trueValue);
printf("Enter Approximate Value : ");
scanf("%f",&approximateValue) ;
float absError = absoluteErr(trueValue , approximateValue) ;
printf("\nAbsolute Error : %f", absError) ;
float relError = relativeErr(trueValue , approximateValue) ;
printf("\nRelative Error : %f", relError ) ;
float perError = percentageErr(trueValue , approximateValue) ;
printf("\nPercentage Error : %f \n", perError ) ;
}