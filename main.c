#include <stdio.h>
#include "splash.h"
#include "login.h"
#include "menu.h"

int main(void) {
    
    displaySplashScreen();
    registerUser();
    loginUser();
    
    
        int choice;
        do {
            
            displayMenu();

            // Asking for the choice of user
            scanf("%d", &choice);
            getchar(); //For a newline

            //Operating with the choice of user
            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    searchBook();
                    break;
                case 3:
                    quitProgram();
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        } while (choice != 3); // Repeat until the user chooses to quit
    

    return 0;
}
