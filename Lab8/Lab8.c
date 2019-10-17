//
// APS105 Lab 8 Lab8.c
//
// This is a program written to maintain a personal music library, 
// using a linked list to hold the songs in the library.
//
// Author: <Sharmin Yousuf
// Student Number: <1004182760>
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.

typedef struct node {
    char *artist ;
    char *songName ;
    char *genre ;
    struct node *nextNode ;
} Node;






// Declarations of support functions
// See below the main function for descriptions of what these functions do
void insertSong(char song[],char artist[],char genere[]);
void printList();
void delete(char songName[]);
void quit();

void inputStringFromUser( char prompt[], char s[], int arraySize ) ;
void songNameDuplicate( char songName[] ) ;
void songNameFound( char songName[] ) ;
void songNameNotFound( char songName[] ) ;
void songNameDeleted( char songName[] ) ;
void artistFound( char artist[] ) ;
void artistNotFound( char artist[] ) ;
void printMusicLibraryEmpty( void ) ;
void printMusicLibraryTitle( void ) ;
Node *head=NULL;
const int MAX_LENGTH = 1024;

void insertSong(char songName[],char artistName[],char genreType[]) //Values passing from the main function
{
    Node *addNew = (Node *) malloc(sizeof (Node)); 

    addNew -> songName = malloc(MAX_LENGTH * sizeof (songName)); //allocates size of the song name
    addNew -> artist = malloc(MAX_LENGTH * sizeof (artistName)); //allocates size of the artist
    addNew -> genre = malloc(MAX_LENGTH * sizeof (genreType)); //allocates size of the genre


    strcpy(addNew -> songName, songName); //3rd column is copied into the 2nd column which is then copied into addNew, addNew is copied into main linked list
    strcpy(addNew -> artist, artistName);
    strcpy(addNew -> genre, genreType);
	//songName, artistName, genreType are userinputs from the main function
	
    Node *temp = NULL; //temp variables to do alphabetical order
    Node *tail = NULL;
    if (head==NULL) 
    {
        head = addNew; //if no previous song, add the first song to the 'stack'
    }
    else if (strcmp(addNew -> songName, head -> songName)<0) //strcmp checks if userInput song name comes before the preexisting song (if song starts with A and the previous song starts with D)
    {
        temp=head; //changes the first position to temp
        head = addNew; //changes the first position to new input
        head->nextNode = temp; //makes the 2nd position of the list temp (first comes head then comes nextnode which is temp)
    }
    else if (strcmp(addNew -> songName, head -> songName)>0 && head->nextNode==NULL) //new user input comes after the preexisting song in the linked list
    {
        head -> nextNode = addNew; //new song is next node
        head -> nextNode ->nextNode= NULL; //next node after new song is null
    }
    else
    {

        while (head!= NULL) //when there is one or more preexisting song 
        {
            if (strcmp(addNew->songName,head->songName)<0) //if userinput song is lesser than head then it will output -1
            {
                temp->nextNode=addNew; //continue to cycle until it is in the appropriate position (checking if new song comes after temp)
                addNew->nextNode=head;
                return;
            }
            temp=head;
            head->nextNode;
        }

    }


}
void delete(char songName[])
{
    Node *temp=NULL; //3 temp nodes
    Node *secondTemp=NULL;
    Node *thirdTemp=head;
    if(strcmp(head->songName, songName) == 0) //check if first song is equal to userInput song 
    {
        temp = head->nextNode; //temp stores everything after head
		free(head->songName);
		free(head->artist);
		free(head->genre);
        free(head); //deletes everything that is in head
        head = temp; //temp comes back to head
    }
    else if(strcmp(head->nextNode->songName, songName) == 0) //checks the second song
    {
        temp = head;
        secondTemp=head->nextNode->nextNode; //stores everything before head
        free(head->songName);
		free(head->artist);
		free(head->genre);
		free(head);
        head = temp;
        head->nextNode=secondTemp;
    }
    else //checks for songs anywhere else in the list
    {
        temp=head->nextNode; //temp stores everything after head
        while (temp != NULL) //cycles until it gets to the song i tneeds to delete
        {
            if (strcmp(temp->songName, songName) == 0)
            {
                thirdTemp->nextNode=temp->nextNode; //third temp stores everything before the deleted song
				free(temp->songName);
				free(temp->artist);
				free(temp->genre);
                free(temp);
                return;
            }
            else
            {
                thirdTemp=thirdTemp->nextNode;
                temp=temp->nextNode;
            }
        }
    }
}
void printList(void) {
    Node *temp = head;
    if (head==NULL) //if first song equals null print empty
        printMusicLibraryEmpty();   // if nothing is in the linked list
    else
    {
        printMusicLibraryTitle();
        while (temp != NULL) { //means head not equal to null essentially
            printf("\n");
            printf("%s\n", temp -> songName);
            printf("%s\n", temp -> artist);
            printf("%s\n", temp -> genre);
            temp = temp -> nextNode;  //print out one by one until get to null
        }
    }
}
bool checkSong(char songName[],int i) //check if the new song is the same as old song (check song and search for song)
{
    Node *temp=head;
    if (!head)
        return false;
    while (temp != NULL)
    {
        if (strcmp(temp -> songName, songName) == 0 && i==0)
        {
            return true;
        }
        if (strcmp(temp -> songName, songName) == 0 && i==1)
        {
            songNameFound(songName);
            printf("\n");
            printf("%s\n", temp -> songName);
            printf("%s\n", temp -> artist);
            printf("%s\n", temp -> genre);
            return true;
        }
        temp=temp->nextNode;
    }
    return false;
}
int main( void ) {
    // Declare the head of the linked list.
    //   ADD YOUR STATEMENT(S) HERE
    int count=0;

    // Announce the start of the program
    printf( "Personal Music Library.\n\n" ) ;
    printf( "%s", "Commands are I (insert), D (delete), S (search by song name),\n"
            "P (print), Q (quit).\n" ) ;

    char response ;
    char input[ MAX_LENGTH + 1 ] ;
    do {
        inputStringFromUser( "\nCommand", input, MAX_LENGTH ) ;

        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper( input[0] ) ;

        if( response == 'I' )
        {
            // Insert a song into the linked list.
            // Maintain the list in alphabetical order by song name.
            //   ADD STATEMENT(S) HERE

            // USE THE FOLLOWING STRINGS WHEN PROMPTING FOR DATA:
            //    char *promptName = "Song name" ;
            //    char *promptArtist =  "Artist" ;
            //    char *promptGenre = "Genre" ;

            char song[MAX_LENGTH+1]; //Declaring array size
            char artist[MAX_LENGTH+1];
            char genre[MAX_LENGTH+1];

            inputStringFromUser("Song name",song, MAX_LENGTH); //Calling inputString function, and sending appropriate values
            inputStringFromUser("Artist",artist, MAX_LENGTH);
            inputStringFromUser("Genre",genre, MAX_LENGTH);

            if(checkSong(song,0)==true) //Checking if the newly entered song in the linked list already exists
            {
                songNameDuplicate(song); //sends to duplicate function to print that it is a duplicate
            }
            else
            {
                insertSong(song, artist, genre); //If it is a new song (not duplicate) it sends to the insertSong function
            }
        }
        else if( response == 'D' ) {
            // Delete a song from the list.

            char *prompt = "\nEnter the name of the song to be deleted" ;
            char song[MAX_LENGTH+1];
            inputStringFromUser(prompt,song, MAX_LENGTH);
            if(checkSong(song,0)==true)
            {
                delete(song);
                songNameDeleted(song);
            }
            else
            {
                songNameNotFound(song);
            }
            //   ADD STATEMENT(S) HERE

        }
        else if( response == 'S' ) {
            // Search for a song by its name.

            char *prompt = "\nEnter the name of the song to search for" ;
            char song[MAX_LENGTH+1];
            inputStringFromUser(prompt,song, MAX_LENGTH);
            if(checkSong(song,1)==false)
            {
                songNameNotFound(song);
            }
            //   ADD STATEMENT(S) HERE

        }
        else if( response == 'P' ) {
            // Print the music library.
            printList();
            //   ADD STATEMENT(S) HERE

        }
        else if( response == 'Q' ) {
            quit();
            // do nothing, we'll catch this below
        }
        else {
            // do this if no command matched ...
            printf( "\nInvalid command.\n" ) ;
        }
    } while( response != 'Q' ) ;

    // Delete the entire linked list.
    //   ADD STATEMENT(S) HERE

    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE

    return 0 ;
}
void quit(void)
{
    while (head != NULL) //deleting all songs until head reaches the null position
    {
        songNameDeleted(head->songName);
        head = head->nextNode; //head becomes the next song
    }
	free(head->songName);
	free(head->artist);
	free(head->genre);
    free(head);
    printMusicLibraryEmpty();
}

// Support Function Definitions

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char prompt[], char s[], int maxStrLength) {
    int i = 0;
    char c;

    printf( "%s --> ", prompt ) ;
    while( i < maxStrLength && (c = getchar()) != '\n' )
        s[i++] = c ;
    s[i] = '\0' ;
}

// Function to call when the user is trying to insert a song name 
// that is already in the personal music library.
void songNameDuplicate( char songName[] ) {
    printf( "\nA song with the name '%s' is already in the music library.\n"
                    "No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound( char songName[] ) {
    printf( "\nThe song name '%s' was found in the music library.\n",
            songName ) ;
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound( char songName[] ) {
    printf( "\nThe song name '%s' was not found in the music library.\n",
            songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted( char songName[] ) {
    printf( "\nDeleting a song with name '%s' from the music library.\n",
            songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void) {
    printf( "\nThe music library is empty.\n" ) ;
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void) {
    printf( "\nMy Personal Music Library: \n" ) ;
}

// Add your functions below this line.

//   ADD STATEMENT(S) HERE
