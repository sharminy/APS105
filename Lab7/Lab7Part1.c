#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void computer(char board[][26],int n,char c,bool turn);
bool moves(char board[][26],int n, char c, bool turn);
void userInputCheck(char board[][26],int n,char row,char col,char c,bool turn,bool my);
void askUser(char board[][26],int n,char c,bool turn);
void printBoard(char board[][26], int n);
bool positionInBounds(int n, char row, char col);
void callFunc(char board[][26],int n,char c,bool turn);
bool validate(char board[][26], int n, int r, int c, char colour, int deltaRow, int deltaCol, int *counterS);
void checkWin(char board[][26],int n, char c,bool moveCheck);
bool checkSpaces(char board[][26], int n);

void printBoard(char board[][26], int n) //Print board
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
bool fun(char board[][26], int n, int r, int c, char colour, int deltaRow, int deltaCol, int *X,int *Y, int *counterS) //for computer
{   //Check if a move is valid in a particular direction, if it is, it sends the directions back to the moves function through pointers X and Y, also sends how many coins it can flip in that direction using that move

    //printf("\nHey");
    char letter;
    int counter=0;
    if(colour=='U')
    {
        return false;
    }
    else if(colour=='W') //Checking for opposite colour to flip into my own colour
    {
        letter='B';
    }
    else if(colour=='B')
    {
        letter ='W';
    }
    int x=deltaRow+r; //Incrementing in that direction
    int y=deltaCol+c;
    while(true) //Checks until no more opposite colours can be found in that direction to flip or the program finds an empty space
    {
        if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == letter)
        {
            x=x+deltaRow;
            y=y+deltaCol;
            counter++;
        }
        else if(board[x][y] == letter && board[x+deltaRow][y+deltaCol] == 'U' && board[r][c]==colour)
        {
            *X=x+deltaRow; //Sends the empty position to the moves function
            *Y=y+deltaCol;
            counter++;
            *counterS=counter; //Sends how many coins can be flipped in that direction
            //printf("\n%c%c %d\n",x+deltaRow+'a',y+deltaCol+'a',*counterS);
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
//For user
bool validate(char board[][26], int n, int r, int c, char colour, int deltaRow, int deltaCol, int *counterS) { //like the FUN function, checking if the move is right or wrong in that direction
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
            else if (board[x][y] == letter && board[x + deltaRow][y + deltaCol] == letter)
            {
                x = x + deltaRow;
                y = y + deltaCol;
                if(x==n || y==n)
                {
                    return false;
                }
            }
            else if (fabs(x) <= n || fabs(y) <= n)
            {
                return false;
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

void userInputCheck(char board[][26],int n,char row,char col,char c, bool turn,bool my) //Flipping function
{
    int increaseX=0,increaseY=0;
    int X,Y,counterS=0;
    //printf("Hyeve");

    //printf("\nHey");
    bool hello=false;
    bool gege=false;

    int counter=0;
    int p,m,i;
    for (p = -1; p < 2; p++) { //takes every direction and checks through the validate function which is similar to the FUN function, but this function will only return true and number of flips
        for (m = -1; m < 2; m++) {
            //printf("\nHey");
            if(validate(board, n, row-'a', col-'a', c, p, m,&counterS)) //if validate is true, will flip all the coins in that direction
            {
                //printf("%d",counterS);
                increaseX=row-'a';
                increaseY=col-'a';
                for(i=0;i<=counterS;i++)//runs the number of times the flips are needed
                {
                    board[increaseX][increaseY]=c;
                    increaseX=increaseX+p; //incrementation of direction
                    increaseY=increaseY+m; //incrementation of direction
                }
            }

        }
    }
    if(my==true)
    {
        callFunc(board, n, c, turn); //If moves are still left, callFunc is called to make the opposite player's move(their turn)
    }
    else if (my==false) //if No moves are left, prints the board and checks for the winner
    {
        printBoard(board,n);
        checkWin(board,n,c,false);
    }
}
bool hello(char board[][26],int n,char row,char col,char c) //same as fun, for user
{
    int counterS=0;
    int counter=0;
    int p,m;
    for (p = -1; p < 2; p++) {
        for (m = -1; m < 2; m++) { //creates 8 direction, sends to validate, if validate says its true

            if(validate(board, n, row-'a', col-'a', c, p, m,&counterS))
            {
                counter++;
            }
        }
    }
    if(counter>0)
    {
        return true; //sends to checkUserInput, which will the then execute the move
    } 
    else
    {
        return false;
    }
}
void callFunc(char board[][26],int n,char c,bool turn) //Switching between user input and computer input
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
    if (turn == true) //user's turn
    {
        turn = false;
        printBoard(board, n);
        askUser(board, n, sendColour, turn);
    }
    else if (turn == false) { //computer's turn
        turn = true;
        printBoard(board, n);
        computer(board, n, sendColour, turn);
    }
}

bool moves(char board[][26],int n, char c, bool turn) //Computes the available positions where the computer can make its move based on the algorithm in lab manual
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
    for(i =0; i<n;i++) //Cycles through all the characters in the array to check available moves
    {
        for(j=0; j<n; j++)
        {   if(board[i][j]!='U') //Check any space in the array that is not U (U is empty space)
            {
                countNumberOfTimes=0;//Used for Computer AI
                for (p = -1; p < 2; p++) //Cycles through all the directions (N and S)
                {
                    for (m = -1; m < 2; m++) //Cycles through E & W
                    {
                        if(p!=0 || m!=0) //Excludes the position of the present move itself
                        {
                            if(fun(board, n, i, j, c, p, m, &X, &Y,&counterS))//Sends board, board size, position in the array, character(W or B, directions, pointers X & Y to obtain the ideal direction and execute it in moves, pointer Counter S is for algorithm
                            {
                                //Algorithm to find move that will flip the most of the opponent's colour
                                if(counterS>tempCounter)  //Creates a temp value for the row, col, and the number of flips, and stores the first run, and compares it with future runs, if future runs have greater number of flips, temp is replaced
                                {
                                    tempCounter=counterS; //stores highest number of flips
                                    tempRow=X;//storing the x position of the highest number of flips
                                    tempCol=Y;
                                    countNumberOfTimes++; //Increment direction
                                }
                                else if(counterS==tempCounter) //if number of flips are the same for 2 runs
                                {
                                    if(tempRow>X) //If number of runs are the same then the lower row will go first ie/a will go before c
                                    {
                                        tempCounter = counterS;
                                        tempRow = X;
                                        tempCol = Y;
                                        countNumberOfTimes++;
                                    }
                                    else if(tempRow==X) //If number of runs are the same then the lower col will go first
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
                            }
                        }
                    }
                }
            }
            if(countNumberOfTimes>tempFinalCount) //If the placement of one tile can change more than one direction, make that move
            {
                tempFinalCount=countNumberOfTimes;
                tempFinalRow=tempRow;
                tempFinalCol=tempCol;
            }
            else if(countNumberOfTimes=tempFinalCount) 
            {
                if(tempFinalRow>tempRow) //Storing the value with the most number of flips
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
    if(tempFinalRow >=0 &&tempFinalRow<26) //After computing the algorithm, takes the final move, and sends it for execution through userInputCheck
    {
        printf("Computer places %c at %c%c.\n", c, tempFinalRow + 'a', tempFinalCol + 'a'); //Prints move of computer
        userInputCheck(board, n, tempFinalRow + 'a', tempFinalCol + 'a', c, turn,true); //sends move to userInputCheck
    }
    else
    {
        printf("%c player has no valid move.\n",c); //If move is not between 0 & 26 (letters of alphabet), the comp does not have any valid moves
        if(checkSpaces(board,n)) //Checks for empty spaces, if it exists, prompts the user to input
        {
            char row, col,letter;
            if (c == 'W') {
                letter = 'B';
            } else if (c == 'B') { //Switching colour for user's input since so far the computer has made its move or can't make another
                letter = 'W';
            }
            printf("Enter move for colour %c (RowCol): ",letter);
            scanf("\n%c%c", &row, &col);
            if (hello(board,n,row,col,letter)) //Checks if userInput is correct
            {
                userInputCheck(board, n, row,col, letter, turn,false); //Executes the move by sending to userInputCheck
            }
        }
    }
    //printf("\nhelel");
}
void askUser(char board[][26],int n,char c,bool turn)
{
    char row,col;
    printf("Enter move for colour %c (RowCol): ",c); //user Input
    scanf("\n%c%c", &row, &col);
    //printf("%c%c", row, col);
    if(checkSpaces(board,n)) //Checks if there are empty spaces
    {
        if (hello(board,n,row,col,c)) //checks if user input is valid
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
        printf("%c player has no valid move.",c); //If no empty spaces, prints the warning
        checkWin(board, n, c, false); //checks for winner
    }
}
bool checkSpaces(char board[][26], int n) //Checks if there is U in the array
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
void checkWin(char board[][26],int n, char c,bool moveCheck) //When there are no valid moves or empty spaces left, the program ends and checks for the winner
{
    char letter;
    int numberOfB;
    int numberOfW;
    int i,j;
    if(moveCheck==true) //user enters invalid input, computer wins
    {
        if (c == 'W') {
            letter = 'B';
        } else if (c == 'B') {
            letter = 'W';
        }
        printf("\n%c player wins.\n",letter);
    }
    else if(moveCheck==false) //user inputs valid input, but no spaces left
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]=='B') //Checks who has the most b's
                {
                    numberOfB++;
                }
                else if(board[i][j]=='W')
                {
                    numberOfW++;
                }
            }
        }
        if(numberOfB>numberOfW) //prints winner
        {
            printf("%c player wins.\n",'B');
        }
        else
        {
            printf("%c player wins.\n",'W');
        }
    }
}
void computer(char board[][26],int n,char c,bool turn) //Takes board, board size, computer's colour, and its turn
{
    moves(board,n,c,turn); //sends to moves
}
int main(void)
{
    int numberOfRows,n;
    char C;
    bool turn =true;
    char board[26][26];
    printf("Enter the board dimension: "); //User Input dimensions
    scanf("%d", &numberOfRows);
    n=numberOfRows;
    printf("Computer plays (B/W) : "); //Computer's tile (Black or White)
    scanf("\n%c",&C);
    //C='W';
    int i,j;
    for(i=0;i<n;i++) //Configuring the board
    {
        for(j=0;j<n;j++)
        {
            if(i==(n/2 - 1) && j==(n/2 - 1) || i == (n/2) && j==(n/2)) //Initializes alternate positions for White
            {
                board[i][j]='W';
            }
            else if(i==(n/2 - 1) && j==(n/2) || i == (n/2) && j==(n/2 - 1)) //Initializes alternate positions for Black
            {
                board[i][j]='B';
            }
            else
            {
                board[i][j]='U';
            }
        }
    }
    printBoard(board,n); //Print board
    if(C=='B') //If computer's move is black, computer goes first
    {
        turn=true; //Flips between user and computer's turns
        computer(board,n,C,turn); //Computer's move
    }
    else if (C=='W') //User goes first
    {
        turn=false;
        askUser(board,n,'B',turn); //User's move
    }

    return 0;
}