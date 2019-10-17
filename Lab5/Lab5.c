#include <stdio.h>
int main()
{
    int numberOfRows;
    do
    {
        printf("Enter the number of rows: ");
        scanf("%d",&numberOfRows);
        triangle(numberOfRows);
    }
    while(numberOfRows>=0);
    return 0;
}
int triangle(int numberOfRows)
{
    int i,m,s,spaces=0,num;
    if(numberOfRows==1) printf("1\n");
    else if(numberOfRows !=0)
    {
        for(m=0;m<(numberOfRows);m++)
        {
            for(s=1;s<(numberOfRows-m);s++) printf("   ");
            for(i=0;i<(m+1);i++)
            {
                printf("%-6d",choose(m,i));
            }
            spaces++;
            printf("\n");
        }
    }
    return 0;
}
int factorial(int f)
{
    int i,fact=1;
    if(f!=0)
    {
        for(i=1;i<=f;i++)
        {
            fact=fact*i;
        }
    }
    else fact=1;
    return fact;   
}
int choose(int n, int r)
{
    int C, nFact,rFact,diffFact;
    nFact=factorial(n);
    rFact=factorial(r);
    diffFact=factorial(n-r);
    C=(nFact)/(rFact*diffFact);
    return C;
}