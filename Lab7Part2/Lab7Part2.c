#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void computer(char board[][26],int n,char c,bool turn);
bool moves(char board[][26],int n, char c, bool turn);
void userInputCheck(char board[][26],int n,char row,char col,char c,bool turn,bool my);
void askUser(char board[][26],int n,char c,bool turn);
void printBoard(char board[][26], int n);

void callFunc(char board[][26],int n,char c,bool turn);
bool validate(char board[][26], int n, int r, int c, char colour, int deltaRow, int deltaCol, int *counterS);
void checkWin(char board[][26],int n, char c,bool moveCheck);
bool checkSpaces(char board[][26], int n);
int moveReturn(int n, int row, int col);
void createTempBoard(char board[][26],int n, char c, int *recordZero, int *recordOne, int *recordTwo, int *recordThree, int *recordFour);

bool smaterMoves(char board[][26],int n, char c, bool turn);
bool hello(char board[][26],int n,char row,char col,char c);
char flipCoin(char c);
void justTryingMyBest(char board[][26],int n, char c, int *recordZero, int *recordOne, int *recordTwo, int *recordThree, int *recordFour);

bool fun(char board[][26], int n, int r, int c, char colour, int deltaRow, int deltaCol, int *X,int *Y, int *counterS);
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
}
bool fun(char board[][26], int n, int r, int c, char colour, int deltaRow, int deltaCol, int *X,int *Y, int *counterS)
{
    //printf("\nHey");
    char letter;
    int counter=0;
    if(colour=='U')
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
            counter++;
        }
        else if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == 'U' && board[r][c]==colour)
        {
            *X=x+deltaRow;
            *Y=y+deltaCol;
            counter++;
            *counterS=counter;
            //printf("\n%c%c %d\n",x+deltaRow+'a',y+deltaCol+'a',*counterS);
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool validate(char board[][26], int n, int r, int c, char colour, int deltaRow, int deltaCol, int *counterS) {
    //printf("\nHey");
    char letter;
    int counter = 0;
    if (colour == 'W') {
        letter = 'B';
    } else if (colour == 'B') {
        letter = 'W';
    }
    int x = deltaRow + r;
    int y = deltaCol + c;
    while (true) {

        if (deltaRow != 0 || deltaCol != 0)
        {
            if (board[x][y] == letter && board[x + deltaRow][y + deltaCol] == letter)
            {
                x = x + deltaRow;
                y = y + deltaCol;
                counter++;
            }
            else if (board[x][y] == letter && board[x + deltaRow][y + deltaCol] == colour)
            {
                x = x + deltaRow;
                y = y + deltaCol;
                //printf("\nHey");
                counter++;
                *counterS=counter;
                //printf("\n%c%c %d\n", x + 'a', y+ 'a', *counterS);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}
void userInputCheck(char board[][26],int n,char row,char col,char c, bool turn,bool my)
{
    int increaseX=0,increaseY=0;
    int X,Y,counterS=0;
    //printf("Hyeve");

    //printf("\nHey");
    bool hello=false;
    bool gege=false;

    int counter=0;
    int p,m,i;
    for (p = -1; p < 2; p++) {
        for (m = -1; m < 2; m++) {
            //printf("\nHey");
            if(validate(board, n, row-'a', col-'a', c, p, m,&counterS))
            {
                //printf("%d",counterS);
                increaseX=row-'a';
                increaseY=col-'a';
                for(i=0;i<=counterS;i++)
                {
                    board[increaseX][increaseY]=c;
                    increaseX=increaseX+p;
                    increaseY=increaseY+m;
                }
            }

        }
    }
    if(my==true)
    {
        callFunc(board, n, c, turn);
    }
    else if (my==false)
    {
        printBoard(board,n);
        checkWin(board,n,c,false);
    }
}
bool hello(char board[][26],int n,char row,char col,char c)
{
    int increaseX=0,increaseY=0;
    int X,Y,counterS=0;
    int counter=0;
    int p,m;
    for (p = -1; p < 2; p++) {
        for (m = -1; m < 2; m++) {

            if(validate(board, n, row-'a', col-'a', c, p, m,&counterS))
            {
                counter++;
            }

        }
    }
    if(counter>0)
    {
        return true;
    } else{
        return false;
    }
}
void callFunc(char board[][26],int n,char c,bool turn)
{
    char sendColour;
    if(c=='B')
    {
        sendColour='W';
    }
    else if(c=='W')
    {
        sendColour='B';
    }
    if (turn == true)
    {
        turn = false;
        printBoard(board, n);
        askUser(board, n, sendColour, turn);
    }
    else if (turn == false) {
        turn = true;
        printBoard(board, n);
        computer(board, n, sendColour, turn);
    }
}
bool moves(char board[][26],int n, char c, bool turn)
{
    int X,Y;
    int counterS=0;
    int tempCounter=0;
    int tempRow=0;
    int tempCol=0;
    int tempFinalRow;
    int tempFinalCol;
    int countNumberOfTimes=0;
    int tempFinalCount=0;
    int i,j,p,m;
    for(i =0; i<n;i++)
    {
        for(j=0; j<n; j++)
        {   if(board[i][j]!='U')
            {
                countNumberOfTimes=0;
                for (p = -1; p < 2; p++)
                {
                    for (m = -1; m < 2; m++)
                    {
                        if(p!=0 || m!=0)
                        {
                            if(fun(board, n, i, j, c, p, m, &X, &Y,&counterS))
                            {
                                if(counterS>tempCounter)
                                {
                                    tempCounter=counterS;
                                    tempRow=X;
                                    tempCol=Y;
                                    countNumberOfTimes++;
                                }
                                else if(counterS==tempCounter)
                                {
                                    if(tempRow>X)
                                    {
                                        tempCounter = counterS;
                                        tempRow = X;
                                        tempCol = Y;
                                        countNumberOfTimes++;
                                    }
                                    else if(tempRow==X)
                                    {
                                        if(tempCol>Y)
                                        {
                                            tempCounter = counterS;
                                            tempRow = X;
                                            tempCol = Y;
                                            countNumberOfTimes++;
                                        }
                                    }
                                }
                                // printf("%d",countNumberOfTimes);


                            }
                        }
                    }
                }
                if(countNumberOfTimes>tempFinalCount)
                {
                    tempFinalCount=countNumberOfTimes;
                    tempFinalRow=tempRow;
                    tempFinalCol=tempCol;
                }
                else if(countNumberOfTimes==tempFinalCount)
                {
                    if(tempFinalRow>tempRow)
                    {
                        tempFinalCount=countNumberOfTimes;
                        tempFinalRow=tempRow;
                        tempFinalCol=tempCol;
                    }
                    else if(tempFinalRow==tempRow)
                    {
                        if(tempFinalCol>tempCol)
                        {
                            tempFinalCount=countNumberOfTimes;
                            tempFinalRow=tempRow;
                            tempFinalCol=tempCol;
                        }
                    }
                }
            }

        }
    }
    if(tempFinalRow>=0 && tempFinalRow<26) {
        printf("Computer places %c at %c%c.\n", c, tempFinalRow + 'a', tempFinalCol + 'a');
        userInputCheck(board, n, tempFinalRow + 'a', tempFinalCol + 'a', c, turn,true);
    }
    else
    {
        printf("%c player has no valid move.\n",c);
        if(checkSpaces(board,n))
        {
            printf("Hey");
            char letter;
            if (c == 'W') {
                letter = 'B';
            } else if (c == 'B') {
                letter = 'W';
            }
            int row, col;
            printf("Enter move for colour %c (RowCol):",c);

            //findSmarterMove(board, n, c, &row, &col);
            //printf("Testing AI move (row, col): %c%c\n", row + 'a', col + 'a');
            scanf("\n%c%c", &row, &col);
            if (hello(board,n,row+'a',col+'a',letter))
            {
                userInputCheck(board, n, row+'a',col+'a', letter, turn,false);
            }
        }
    }
    //printf("\nhelel");
    return true;
}
bool smarterMoves(char board[][26],int n, char c, bool turn)
{

    int X,Y;
    int counterS=0;

    int initialRow[n*n];
    int initialCol[n*n];
    int initialNumberOfMoves[n*n];
    int counter=0;
    int i,j,p,m,h,y;
    for(i =0; i<n;i++)
    {
        for(j=0; j<n; j++)
        {   if(board[i][j]!='U')
            {
                for (p = -1; p < 2; p++)
                {
                    for (m = -1; m < 2; m++)
                    {
                        if(p!=0 || m!=0)
                        {
                            if(fun(board, n, i, j, c, p, m, &X, &Y,&counterS))//stores all the avaliable moves
                            {
                                initialRow[counter]=X;
                                initialCol[counter]=Y;
                                initialNumberOfMoves[counter]=counterS;
                                counter++;
                            }
                        }
                    }
                }

            }

        }
    }
    //sorts all the avaliable moves based on highest number of flips

    int recordMoves;
    int recordZero=0;
    int recordOne=0;
    int recordTwo=0;
    int recordThree=0;
    int recordFour=0;
    bool moveOn=true;

    int tempFinalRow[n*n];
    int tempFinalCol[n*n];
    int tempFinalScore[n*n];
    int tempFinalCount[n*n];
    int secondCounter=0;


    for(i=0;i<counter;i++)
    {
        moveOn=true;
        if(moveReturn(n,initialRow[i],initialCol[i]) == 0 && (moveOn))
        {
            createTempBoard(board,n,c,&recordZero,&recordOne,&recordTwo,&recordThree,&recordFour);
            if(recordZero<2 && recordOne <= 2)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=10;
                secondCounter++;
                moveOn=false;
            }
            else if(recordZero==0 && recordOne<=3)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=8;
                secondCounter++;
                moveOn=false;
            }
        }
        if (moveReturn(n,initialRow[i],initialCol[i]) == 1 && (moveOn))
        {
            createTempBoard(board,n,c,&recordZero,&recordOne,&recordTwo,&recordThree,&recordFour);
            if(recordZero==0 && recordOne<=3)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=7;
                secondCounter++;
                moveOn=false;
            }
            else if(recordOne<=2 && recordTwo<=3)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=6;
                secondCounter++;
                moveOn=false;
            }
        }
        if(moveReturn(n,initialRow[i],initialCol[i]) == 2 && (moveOn))
        {
            createTempBoard(board,n,c,&recordZero,&recordOne,&recordTwo,&recordThree,&recordFour);
            if(recordZero==0 && recordOne<=1)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=5;
                secondCounter++;
                moveOn=false;
            }
            else if(recordTwo<=2 && recordThree<=3)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=4;
                secondCounter++;
                moveOn=false;
            }
        }
        if(moveReturn(n,initialRow[i],initialCol[i]) == 3 && n>=6 && (moveOn))
        {
            createTempBoard(board,n,c,&recordZero,&recordOne,&recordTwo,&recordThree,&recordFour);
            if(recordZero==0 && recordOne==0)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=3;
                secondCounter++;
                moveOn=false;
            }
            else if(recordOne<=1 && recordTwo<=2)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=2;
                secondCounter++;
                moveOn=false;
            }
            else if(recordTwo<=1 && recordThree<=3)
            {
                tempFinalRow[secondCounter]=initialRow[i];
                tempFinalCol[secondCounter]=initialCol[i];
                tempFinalCount[secondCounter]=initialNumberOfMoves[i];
                tempFinalScore[secondCounter]=1;
                secondCounter++;
                moveOn=false;
            }
        }
        if(moveReturn(n,initialRow[i],initialCol[i]) == 4 && n>=8 && (moveOn))
        {
            tempFinalRow[secondCounter]=initialRow[i];
            tempFinalCol[secondCounter]=initialCol[i];
            tempFinalCount[secondCounter]=initialNumberOfMoves[i];
            tempFinalScore[secondCounter]=0;
            secondCounter++;
            moveOn=false;
        }
    }

    //sorting
    int finalRow;
    int finalCol;
    int finalScore;
    int finalMoves;

    for(h=0; h<secondCounter;h++)
    {
        for(y=0; y<secondCounter-1-h;y++) {
            if (tempFinalScore[y] > tempFinalScore[y + 1]) {
                finalRow = tempFinalRow[y + 1];
                finalCol = tempFinalCol[y + 1];
                finalScore = tempFinalScore[y + 1];
                finalMoves = tempFinalCount[y + 1];


                tempFinalRow[y + 1] = tempFinalRow[y];
                tempFinalCol[y + 1] = tempFinalCol[y];
                tempFinalScore[y + 1] = tempFinalScore[y];
                tempFinalCount[y + 1] = tempFinalCount[y];


                tempFinalRow[y] = finalRow;
                tempFinalCol[y] = finalCol;
                tempFinalScore[y] = finalScore;
                tempFinalCount[y] = finalMoves;
            } else if (tempFinalScore[y] == tempFinalScore[y + 1]) {
                if(tempFinalCount[y]>tempFinalCount[y+1])
                {
                    finalRow = tempFinalRow[y + 1];
                    finalCol = tempFinalCol[y + 1];
                    finalScore = tempFinalScore[y + 1];
                    finalMoves = tempFinalCount[y + 1];


                    tempFinalRow[y + 1] = tempFinalRow[y];
                    tempFinalCol[y + 1] = tempFinalCol[y];
                    tempFinalScore[y + 1] = tempFinalScore[y];
                    tempFinalCount[y + 1] = tempFinalCount[y];


                    tempFinalRow[y] = finalRow;
                    tempFinalCol[y] = finalCol;
                    tempFinalScore[y] = finalScore;
                    tempFinalCount[y] = finalMoves;
                }
            }
        }
    }
    if(tempFinalRow[0]>=0 && tempFinalRow[0]<26)
    {
        printf("Computer places %c at %c%c.\n", c, tempFinalRow[0] + 'a', tempFinalCol[0] + 'a');
        userInputCheck(board, n, tempFinalRow[0] + 'a', tempFinalCol[0] + 'a', c, turn,true);
    }
    else
    {
        printf("%c player has no valid move.\n",c);
        if(checkSpaces(board,n))
        {
            char letter;
            if (c == 'W') {
                letter = 'B';
            } else if (c == 'B') {
                letter = 'W';
            }
            int row,col;
            printf("Enter move for colour %c (RowCol):",c);

            //findSmarterMove(board, n, c, &row, &col);
            //printf("Testing AI move (row, col): %c%c\n", row + 'a', col + 'a');
            scanf("\n%c%c", &row, &col);
            if (hello(board,n,row,col,letter))
            {
                userInputCheck(board, n, row,col, letter, turn,false);
            }
        }
        else
        {
            checkWin(board,n,c,false);
        }
    }
    return true;
}

void createTempBoard(char board[][26],int n, char c, int *recordZero, int *recordOne, int *recordTwo, int *recordThree, int *recordFour)
{
    char tempBoard[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tempBoard[i][j]=board[i][j];
        }
    }
    justTryingMyBest(tempBoard,n,c,&recordZero,&recordOne,&recordTwo,&recordThree,&recordFour);
}
void justTryingMyBest(char board[][26],int n, char c, int *recordZero, int *recordOne, int *recordTwo, int *recordThree, int *recordFour)
{
    char flippedColour;
    flippedColour=flipCoin(c);
    int h,j,p,m,X,Y;
    int counterS=0;
    for(h =0; h<n;h++)
    {
        for(j=0; j<n; j++)
        {   if(board[h][j]!='U')
            {
                for (p = -1; p < 2; p++)
                {
                    for (m = -1; m < 2; m++)
                    {
                        if(p!=0 || m!=0)
                        {
                            if(fun(board, n, h, j,flippedColour, p, m, &X, &Y,&counterS))//stores all the avaliable moves
                            {
                                if(moveReturn(n,X,Y)==0)
                                {
                                    *recordZero++;
                                }
                                else if(moveReturn(n,X,Y)==1)
                                {
                                    *recordOne++;
                                }
                                else if(moveReturn(n,X,Y)==2)
                                {
                                    *recordTwo++;
                                }
                                else if(moveReturn(n,X,Y)==3 && n>=6)
                                {
                                    *recordThree++;
                                }
                                else if(moveReturn(n,X,Y)==4 && n>=8)
                                {
                                    *recordFour++;
                                }
                            }
                        }
                    }
                }

            }

        }
    }
}
char flipCoin(char c)
{
    if (c == 'W')
    {
        return 'B';
    }
    else if (c == 'B')
    {
        return 'W';
    }
}
int moveReturn(int n, int row, int col)
{
    char grid[n][n];
    int i,j,k,l,m;

    grid[0][0]=0;
    grid[0][n-1]=0;
    grid[n-1][0]=0;
    grid[n-1][n-1]=0;

    grid[n/2 -1][n/2 -1]=1;
    grid[n/2][n/2]=1;
    grid[n/2][n/2 -1]=1;
    grid[n/2 -1][n/2]=1;

    if(n>4)
    {
        for(i=0;i<=(n-1);i++)
        {
            if(i==0 && i==(n-1))
            {
                for(j=1;j<=(n-2);j++)
                {
                    grid[i][j]=2;
                }
            }
            else if(i>0 && i<=(n-2))
            {
                grid[i][0]=2;
                grid[i][n-1]=2;
            }
        }
        for(i=1;i<=(n-2);i++)
        {
            if(i==1 && i==(n-2))
            {
                for(j=1;j<=(n-2);j++)
                {
                    grid[i][j]=3;
                }
            }
            else if(i>1 && i<(n-3))
            {
                grid[i][1]=3;
                grid[i][n-2]=3;
            }
        }
        if(n>6)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(grid[i][j]!=0 ||grid[i][j]!=1||grid[i][j]!=2||grid[i][j]!=3 )
                    {
                        grid[i][j]=4;
                    }
                }
            }
        }
    }

    return grid[row][col];

}

void askUser(char board[][26],int n,char c,bool turn)
{
    int row,col;
    printf("Enter move for colour %c (RowCol):",c);

    //findSmarterMove(board, n, c, &row, &col);
    //printf("Testing AI move (row, col): %c%c\n", row + 'a', col + 'a');
    scanf("\n%c%c", &row, &col);
    //printf("%c%c", row, col);
    if(checkSpaces(board,n))
    {
        if (hello(board,n,row,col,c))
        {
            userInputCheck(board, n, row, col, c, turn,true);
        }
        else
        {
            printf("Invalid move.");
            checkWin(board, n, c, true);
        }
    }
    else
    {
        printf("%c player has no valid move.",c);
        checkWin(board, n, c, false);
    }
}
bool checkSpaces(char board[][26], int n)
{
    int numberOfU=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(board[i][j]=='U')
            {
                numberOfU++;
            }
        }
    }
    if(numberOfU>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void checkWin(char board[][26],int n, char c,bool moveCheck)
{
    char letter;
    int numberOfB;
    int numberOfW;
    int i,j;
    if(moveCheck==true)
    {
        if (c == 'W') {
            letter = 'B';
        } else if (c == 'B') {
            letter = 'W';
        }
        printf("\n%c player wins.",letter);
    }
    else if(moveCheck==false)
    {
        numberOfB=0;
        numberOfW=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]=='B')
                {
                    numberOfB++;
                }
                else if(board[i][j]=='W')
                {
                    numberOfW++;
                }
            }
        }
        if(numberOfB>numberOfW)
        {
            printf("\n%c player wins.",'B');
        }
        else
        {
            printf("\n%c player wins.",'W');
        }
    }
}
void computer(char board[][26],int n,char c,bool turn)
{
    smarterMoves(board,n,c,turn);
}
int main(void) {
    int numberOfRows,n;
    char C;
    bool turn =true;
    char board[26][26];
    printf("Enter the board dimension: ");
    scanf("%d", &numberOfRows);
    n=numberOfRows;
    printf("Computer plays (B/W) : ");
    scanf("\n%c",&C);
    //C='W';
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i==(n/2 - 1) && j==(n/2 - 1)) ||( i == (n/2) && j==(n/2)))
            {
                board[i][j]='W';

            }
            else if((i==(n/2 - 1) && j==(n/2) )||( i == (n/2) && j==(n/2 - 1)))
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
    if(C=='B')
    {
        turn=true;
        computer(board,n,C,turn);
    }
    else if (C=='W')
    {
        turn=false;
        askUser(board,n,'B',turn);
    }

    return 0;
}