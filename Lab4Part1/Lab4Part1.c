#include <stdio.h>

int main() 
{  
    int numberOfRows, temp,i,x,q,p, m=0;
    printf("Enter the number of rows in the triangle: ");
    scanf("%d",&numberOfRows);
    temp=numberOfRows;
	
    for (i =1; i<=numberOfRows; i++)
    {
        if(i==1)
        {
            for( x=1; x<numberOfRows;x++)
            {
                printf(" ");
            }
            printf("^");
            m++;
        }
        else if(i==numberOfRows)
        {
            printf("\n");
            for( p=1; p<=(numberOfRows);p++)
            {
                printf("^");
            }
            for( q=1;q<=m;q++)
            {
                printf("^");
            }
        }
        else
        {
            printf("\n");
            for( p=1; p<(numberOfRows-m);p++)
            {
                printf(" ");
            }
            printf("^");
            for( q=1;q<((m*2));q++)
            {
                printf(" ");
            }
            printf("^");
            m++;
            
        }
    }
	
	printf("\n");
}
