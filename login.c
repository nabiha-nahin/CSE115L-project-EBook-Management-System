#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isRegisteredUser(const char* username) {
    FILE* usersFile = fopen("login.txt", "r");

    if (usersFile == NULL) {
        printf("Failed to open the users file.\n");
        return 0;
    }

    char storedUsername[100];
    while (fscanf(usersFile, "%99[^,\n]\n", storedUsername) == 1) {
        if (strcmp(storedUsername, username) == 0) {
            fclose(usersFile);
            return 1; // User found
        }
    }

    fclose(usersFile);
    return 0; // User not found
}

int registerUser() {
    char username[100];
    char password[100];

    printf("Enter your username: ");
    scanf("%99s", username);

    if (isRegisteredUser(username)) {
        printf("Username already exists.\n");
        return 0;
    }

    printf("Enter a password: ");
    scanf("%99s", password);

    FILE* usersFile = fopen("login.txt", "a");
    if (usersFile == NULL) {
        printf("Failed to open the users file.\n");
        return 0;
    }

    fprintf(usersFile, "%s,%s\n", username, password);
    fclose(usersFile);

    printf("Registration successful.\n");
    return 1;
}

int loginUser() {
    int i;
    char username[100];
    char password[100];

    printf("Enter your username: ");
    scanf("%99s", username);

    if (username[0] == '\0') {
        printf("Username cannot be empty.\n");
        return 0;
    }

    // Read the usernames from the file
    FILE* usersFile = fopen("login.txt", "r");
    char storedUsernames[100][100];
    int numStoredUsernames = 0;
    while (fscanf(usersFile, "%99[^,\n]\n", storedUsernames[numStoredUsernames]) == 1) {
        numStoredUsernames++;
    }
    fclose(usersFile);


    printf("Enter your password: ");
    scanf("%99s", password);

    // Check if the username is in the array of stored usernames
    for (int i = 0; i < numStoredUsernames; i++) {
        if (strcmp(username, storedUsernames[i]) == 0) {
            // Username found
            break;
        }
    }

    // Check if the password is correct
    if (i == numStoredUsernames) {
        printf("Username not found.\n");
        return 0;
    } else {
        FILE* usersFile = fopen("login.txt", "r");

        char storedUsername[100];
        char storedPassword[100];
        int loginSuccessful = 0;

        while (fscanf(usersFile, "%99[^,\n],%99[^\n]\n", storedUsername, storedPassword) == 2) {
            if (strcmp(storedUsername, username) == 0 && strcmp(storedPassword, password) == 0) {
                loginSuccessful = 1; // User logged in
                break;
            }
        }

        fclose(usersFile);

       
    }
}
