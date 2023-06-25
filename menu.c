#include <stdio.h>
#include "menu.h"

void displayMenu(){

    printf("\n");
    printf("1. Add a book\n");
    printf("2. Search for a book\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

void addBook() {
    
    char title[100];
    char author[100];
    char genre[100];

    printf("Enter the title of the book: ");
    fgets(title, sizeof(title), stdin);
    
    printf("Enter the author of the book: ");
    fgets(author, sizeof(author), stdin);
   
    printf("Enter the genre of the book: ");
    fgets(genre, sizeof(genre), stdin);
    
    printf("Adding a book: %s by %s (%s)", title, author, genre);

 
}

void searchBook() {

    char title[100];
  

    
    printf("Enter the title of the book you want to search for: ");
    fgets(title, sizeof(title), stdin);

    printf("Searching for book: %s\n", title);

}


void quitProgram() {
  
    printf("Thank you for using the E-Book management system.\n");
}
