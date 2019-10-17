#include <stdio.h>

int main() 
{  
    int numberOfRows,i,p,q,space=0; 
    printf("Enter the number of rows in the triangle: "); //User Input
    scanf("%d",&numberOfRows);
	
	
    for(i=1; i<=numberOfRows;i++) //Cycle through number of rows entered
    {
        if(i!=numberOfRows) //Prints everything but last line
        {
            for(p=1; p<(numberOfRows-space);p++) //Prints spaces before the first hat
            {
                printf(" ");
            }
            printf("^"); //Print first hat of every row
			
            if(i!=1) //First line only prints one hat, so doesn't apply to this
            {
                for(q=1;q<(space*2);q++) //Prints spaces in the middle
                {
                    printf(" ");
                }
                printf("^"); //Prints 2nd hat for every line other than first and last line
            }
            space++; 
            printf("\n");
        }
        else
        {
            for(p=1; p<=(numberOfRows*2)-1;p++) //Print last line
            {
                printf("^");
            }
			printf("\n");
        }
    }
}