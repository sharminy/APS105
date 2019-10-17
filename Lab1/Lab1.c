#include <stdio.h>
#include <math.h>
int main (void)
{
	double num1 = 0.0; // User input of 1st number
	double num2 = 0.0; // User input of 2nd number
	double num3 = 0.0; // User input of 3rd number
	double mean = 0.0; // Intialize mean as 0.0

	printf("Enter three numbers: "); // Prompt user to enter numbers

	scanf("%lf%lf%lf",&num1,&num2,&num3); // Store user-entered values into variables

	double total = (num1+num2+num3); //Sum of user-entered values
	mean = (total/3); // Quotient of total and n=3 (3 entered values)

	double sum = pow((num1-mean),2)+pow((num2-mean),2)+pow((num3-mean),2);
	double div = sum/2; // Quotient of sum and n=3-1, since n is constant (3), the denominator is 2)
	double stdev = sqrt(div); // Square root the quotient of the sum and (n-1) to find the standard deviation

	printf("The mean is %.2lf and the standard deviation is %.2lf\n",mean,stdev);//Print final output of mean and standard deviation

return 0;
}

