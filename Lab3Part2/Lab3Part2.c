//This program runs as a basic calculator with the functions addition, subtraction, multiplication, division

#include <stdio.h>

int main() 
{
    char operator; //Declaring variable for mathematical operation
    double firstNum,secondNum,result;

    {
        printf("Enter first number: "); //User input 
        scanf("%lf",&firstNum);

        printf("Enter second number: "); //User input 
        scanf("%lf",&secondNum);

        printf("Enter calculation command (one of a, s, m, or d): "); //User input for calculation operation
        scanf(" %c",&operator);

        if (secondNum==0 && operator=='d') //If denominator is set to 0, error message will appear
        {
            printf("Error, trying to divide by zero\n");
        }
        else if (operator=='a' || operator=='s' ||operator=='m' || operator=='d')
        {
            if (operator=='a') //Check if the operator given is addition operator
            {
                result=firstNum + secondNum; //Addition
                printf("Sum of %0.2lf and %0.2lf is %0.2lf \n", firstNum,secondNum,result); //Result as desired by requirements
            }
            else if (operator=='s')//Check if the operator given is subtraction operator
            {
                result=firstNum - secondNum;//Subtraction
                printf("Difference of %0.2lf from %0.2lf is %0.2lf \n", firstNum,secondNum,result);//Result as desired by requirements
            }
            else if (operator=='m')//Check if the operator given is multiplication operator
            {
                result=firstNum * secondNum;//Multiplication
                printf("Product of %0.2lf and %0.2lf is %0.2lf \n", firstNum,secondNum,result);//Result as desired by requirements
            }
            else if (operator=='d')//Check if the operator given is division operator
            {
                result=firstNum / secondNum;//Division
                printf("Division of %0.2lf by %0.2lf is %0.2lf \n", firstNum,secondNum,result);//Result as desired by requirements
            }
        }
        else
        {
            printf("Error, unknown calculation command given \n");
        }
    }
    return 0;
}

