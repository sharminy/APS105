#include <stdio.h>

int main()
{ 
    int numberOfRows, temp,m=0;
    printf("Enter the number of rows in the traingle: ");
    scanf("%d",&numberOfRows);
    temp=numberOfRows;
    for(int i =1; i<=numberOfRows; i++)
    {
        if(i==1)
        {
            for(int x=1; x<numberOfRows;x++)
            {
                printf(" ");
            }
            printf("^");
            m++;
        }
        else if(i==numberOfRows)
        {
            printf("\n");
            for(int p=1; p<=(numberOfRows);p++)
            {
                printf("^");
            }
            for(int q=1;q<=m;q++)
            {
                printf("^");
            }
        }
        else
        {
            printf("\n");
            for(int p=1; p<(numberOfRows-m);p++)
            {
                printf(" ");
            }
            printf("^");
            for(int q=1;q<((m*2));q++)
            {
                printf(" ");
            }
            printf("^");
            m++;
           
        }
       
    }
   

}

