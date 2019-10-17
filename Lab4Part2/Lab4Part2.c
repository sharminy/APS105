#include <stdio.h>

int main() 
{
    int number;
    char userChoice;


        printf("Enter B for conversion of Binary to Decimal, OR\n"); //User Input
        printf("Enter D for conversion of Decimal to Binary: ");
        scanf("%c",&userChoice);
       
        if(userChoice =='B' || userChoice =='D'  ) //User choice
        {
           
            printf("Enter your number: ");
            scanf("%d",&number);
        }
        else
        {
            printf("Enter your number: Invalid input; Goodbye"); //Invalid input
        }

        if(userChoice == 'B')
        {
            printf("%d in binary = %d in decimal\n",number,convertBinaryToDecimal(number)); //Calling the function & Printing
        }
        else if(userChoice == 'D')
        {
            printf("%d in decimal = %d in binary\n",number,convertDecimalToBinary(number)); //Calling the function & Printing
        }
       
}
int convertBinaryToDecimal(int input)//Create a function with an input 'int'
{
    int leftOutValue, answer=0, initial=1;//variable declaration
    while(input >0)//the code will run until the input is equal to zero
    {
        leftOutValue=input%10;//Modulus division of the input will give the leftOutValue as 1 or 0 depemding upon the user input

        if(leftOutValue==1) //When the leftOutValue value is 1 the code will compute
        {
            answer=answer+initial; //Intial value is the value of the leftOutValue variable of binary in decimal
            //The initial value adds up to total if the leftOutValue is 1
        }
        input=input/10; //Integer division reduces the input, for eg. makes 111 to 11
        initial=initial*2;//Initial value times 2 since the decimal values of binary gets incremented by powers of 2
    }
    return answer;
}

int convertDecimalToBinary(int input)//Create a function with an input 'int'
{
    int leftOutValue, answer=0, initial=1;//Varoable declaration
    while(input >0)//the code will run until the input equals zero
    {
        leftOutValue=input%2;//Modulus division of the input will give the leftOutValue as 1 or 0 depemding upon the user input
        if(leftOutValue!=0)//When the leftOutValue value is not equal to zero the code will compute
        {
            answer=answer+(leftOutValue*initial);//Intial value is the value of the leftOutValue variable of decimal in binary
            //The initial value adds up to total if the leftOutValue is not equal to zero
        }
        input=input/2;//Integer division reduces the input, for eg. makes 11/2 equals 5
        initial=initial*10;//Initial value times 10 since the binary values of decimal as read by users is in tens, hundreds, thousands etc.
    }
    return answer;
}