#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool positionInBounds(int n, char row, char col)
{
    if(row - 'a' < n || col - 'a' < n )
    {
        return true;
    }
    return false;
}
bool checkLegalInDirection(char board[][26], int n, char row, char col, char colour, int deltaRow, int deltaCol)
{
    int r= row-'a';
    int c=col-'a';
    char letter;
    if(colour == 'U')
    {
        return false;
    }
    else if(colour=='W')
    {
        letter='B';
    }
    else if(colour=='B')
    {
        letter ='W';
    }
    int x=deltaRow+r;
    int y=deltaCol+c;

    while(true)
    {
        if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == letter)
        {
            x=x+deltaRow;
            y=y+deltaCol;
        }
        else if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == 'U' && board[r][c]==colour)
        {
            //printf("%c%c\n",(97+x+deltaRow),(97+y+deltaCol));
            return true;
        }
        else if(fabs(x) <=n || fabs(y) <=n)
        {
            return false;
        }
        else
        {
            return false;
        }
    }

}
bool toValidate(char board[][26],int n, char row, char col,char colour, int deltaRow,int deltaCol, char userRow, char userCol)
{
    int r= row-'a';
    int c=col-'a';
    char letter;
    if(colour == 'U')
    {
        return false;
    }
    else if(colour=='W')
    {
        letter='B';
    }
    else if(colour=='B')
    {
        letter ='W';
    }
    int x=deltaRow+r;
    int y=deltaCol+c;

    while(true)
    {
        if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == letter)
        {
            x=x+deltaRow;
            y=y+deltaCol;
        }
        else if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == 'U')
        {
            if(userRow == (char)(97+x+deltaRow) && userCol == (char)(97+y+deltaCol))
            {
                return true;
            }
            break;
        }
        else if(fabs(x) <=n || fabs(y) <=n)
        {
            break;
        }
        else
        {
            break;
        }
    }
    return false;
}
void fun(char board[][26], int n, char row, char col, char colour, int deltaRow, int deltaCol, int *X,int *Y)
{
    int r= row-'a';
    int c=col-'a';
    char letter;
    if(colour=='W')
    {
        letter='B';
    }
    else if(colour=='B')
    {
        letter ='W';
    }
    int x=deltaRow+r;
    int y=deltaCol+c;

    while(true)
    {
        if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == letter)
        {
            x=x+deltaRow;
            y=y+deltaCol;
        }
        else if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == 'U' && board[r][c]==colour)
        {
            *X=x+deltaRow;
            *Y=y+deltaCol;
            break;
        }
        else if(fabs(x) <=n || fabs(y) <=n)
        {
            break;
        }
        else
        {
            break;
        }
    }
}
void moves(char board[][26],int n, char c)
{
    int X,Y;
    int answerX[n*n];
    int answerY[n*n];
    int counter=0;
    printf("Available moves for %c:\n",c);
	int i,j;
    for(i =0; i<n;i++)
    {
        for(j=0; j<n; j++)
        {
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, 1, 1))
            {
                fun(board, n, 'a'+ j,'a'+i, c, 1, 1,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;

            }
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, 1, 0))
            {
                fun(board, n, 'a'+ j,'a'+i, c, 1, 0,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;
            }
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, 1, -1))
            {
                fun(board, n, 'a'+ j,'a'+i, c, 1, -1,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;
            }
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, 0, -1))
            {
                fun(board, n, 'a'+ j,'a'+i, c, 0, -1,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;
            }
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, -1, -1))
            {
                fun(board, n, 'a'+ j,'a'+i, c, -1, -1,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;
            }
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, -1, 0))
            {
                fun(board, n, 'a'+ j,'a'+i, c, -1, 0,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;
            }
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, -1, 1))
            {
                fun(board, n, 'a'+ j,'a'+i, c, -1, 1,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;
            }
            if(checkLegalInDirection(board, n, 'a'+ j,'a'+i, c, 0, 1))
            {
                fun(board, n, 'a'+ j,'a'+i, c, 0, 1,&X,&Y);
                answerX[counter]=X;
                answerY[counter]=Y;
                counter++;
            }

        }
    }

    int temp1,temp2,t,o;
    for (t = 0; t <counter;t++)
    {

        for (o = t + 1; o < counter; o++)
        {

            if (answerX[t] > answerX[o])
            {

                temp1 = answerX[t];
                temp2 = answerY[t];

                answerX[t] = answerX[o];
                answerY[t] = answerY[o];

                answerX[o] = temp1;
                answerY[o] = temp2;

            }
            else if( answerX[t] == answerX[o])
            {
                if (answerY[t] > answerY[o])
                {

                    temp1 = answerX[t];
                    temp2 = answerY[t];

                    answerX[t] = answerX[o];
                    answerY[t] = answerY[o];

                    answerX[o] = temp1;
                    answerY[o] = temp2;

                }
            }

        }

    }
	int e;
    for(e=0;e<counter;e++)
    {
        printf("%c%c\n",(97+answerX[e]),(97+answerY[e]));
    }

}
void printBoard(char board[][26], int n)
{   int i,j;
    int horizontalCounter=0;
    int verticalCounter=0;
    for(i=0; i<(n+1);i++)
    {
        for(j=0;j<(n+2);j++)
        {
            if((i==0 && j==0) ||j==1)
            {
                printf(" ");
            }
            else if(i==0 && j>1)
            {
                printf("%c", 'a'+horizontalCounter);
                horizontalCounter++;
            }
            else if(i>0 && j==0)
            {
                printf("%c", 'a'+verticalCounter);
                verticalCounter++;
            }
            else
            {
                printf("%c",board[i-1][j-2]);
            }
        }
        printf("\n");
    }
    return;
}
void reConfig(char board[][26],int n,char colour, char row, char col, int i, int j, int deltaRow, int deltaCol)
{
    int rows=row-'a';
    int column=col-'a';

    while(true)
    {
        board[rows][column]=colour;
        rows=rows-deltaRow;
        column=column-deltaCol;
        if(rows ==i && column==j)
        {
            printBoard(board,n);
            break;
        }
    }
}
void userInputCheck(char board[][26],int n)
{	int i,j;
    char user, col, row,c;
    bool toCheck=false;
    printf("Enter a move: \n");
    scanf("\n%c%c%c",&user,&row,&col);
    c=user;
    for(i =0; i<n;i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j]==c)
            {

                if(toValidate(board,n,'a'+ i,'a'+j,c,-1,-1,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,-1,-1);
                    toCheck=true;
                }
                else if(toValidate(board,n,'a'+ i,'a'+j,c,-1,0,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,-1,0);
                    toCheck=true;
                }
                else if(toValidate(board,n,'a'+ i,'a'+j,c,-1,1,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,-1,1);
                    toCheck=true;
                }
                else if(toValidate(board,n,'a'+ i,'a'+j,c,0,-1,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,0,-1);
                    toCheck=true;
                }
                else if(toValidate(board,n,'a'+ i,'a'+j,c,0,1,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,0,1);
                    toCheck=true;
                }
                else if(toValidate(board,n,'a'+ i,'a'+j,c,1,-1,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,1,-1);
                    toCheck=true;
                }
                else if(toValidate(board,n,'a'+ i,'a'+j,c,1,0,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,1,0);
                    toCheck=true;
                }
                else if(toValidate(board,n,'a'+ i,'a'+j,c,1,1,row,col))
                {
                    printf("Valid move.\n");
                    reConfig(board,n,c,row,col,i,j,1,1);
                    toCheck=true;
                }
            }

        }
    }
    if(toCheck != true)
    {
        printf("Invalid move.\n");
        printBoard(board,n);
    }

}

void config(char board[][26], int n)
{
    char user, col, row;
    int rows,column;

    printf("Enter the Configuration:\n");
    while(true)
    {
        scanf("\n%c%c%c",&user,&row,&col);
        if(user == '!' && row=='!' && col=='!')
        {
            printBoard(board,n);
            moves(board,n,'W');
            moves(board,n,'B');
            userInputCheck(board,n);
            break;
        }
        else
        {
            if(positionInBounds(n,row,col))
            {
                rows = row - 'a';
                column = col - 'a';
                board[rows][column] = user;
            }
        }
    }
}
void createBoard(char board[][26],int n)
{	int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==(n/2 - 1) && j==(n/2 - 1) || i == (n/2) && j==(n/2))
            {
                board[i][j]='W';

            }
            else if(i==(n/2 - 1) && j==(n/2) || i == (n/2) && j==(n/2 - 1))
            {
                board[i][j]='B';
            }
            else
            {
                board[i][j]='U';
            }
        }
    }
    printBoard(board,n);
    config(board,n);
}

int main(void) {
    int numberOfRows;
    while(true)
    {
        printf("Enter the board dimensions: ");
        scanf("%d", &numberOfRows);
        if(numberOfRows%2==0 && numberOfRows >=4 && numberOfRows<=26)
        {
            char board[numberOfRows][numberOfRows];
            createBoard(board, numberOfRows);
            break;
        }
        else
        {
            printf("Enter an even dimension greater than or equal to 4 and 2less than or equal to 26.");
            break;
        }

    }
    return 0;
}