#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isRegisteredUser(const char* username) {
    FILE* usersFile = fopen("login.txt", "r");

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
    char nsu_id[100];

    printf("Enter a username: ");
    scanf("%99s", username);

    if (isRegisteredUser(username)) {
        printf("Username already exists. Please choose a different username.\n");
        return 0;
    }


      printf("Enter nsu_id: ");
    scanf("%99s", nsu_id);

    printf("Enter a password: ");
    scanf("%99s", password);

    FILE* usersFile = fopen("users.txt", "a");
    if (usersFile == NULL) {
        printf("Failed to open the users file.\n");
        return 0;
    }

    fprintf(usersFile, "%s,%s,%s\n", username, nsu_id, password);
    fclose(usersFile);

    printf("Registration successful.\n");
    return 1;
}

int loginUser() {
    char username[100];
    char nsu_id[100];
    char password[100];

    printf("Enter your username: ");
    scanf("%99s", username);

    if (!isRegisteredUser(username)) {
        printf("Username not found.\n");
        return 0;
    }

    printf("Enter your password: ");
    scanf("%99s", nsu_id);

    printf("Enter your password: ");
    scanf("%99s", password);

    FILE* usersFile = fopen("users.txt", "r");

    char storedUsername[100];
    char storedNsu_ID[100];
    char storedPassword[100];
    int loginSuccessful = 0;

    while (fscanf(usersFile, "%99[^,\n],%99[^,\n],%99[^\n]\n", storedUsername,storedNsu_ID, storedPassword) == 2) {
        if (strcmp(storedUsername, username) == 0 && strcmp(storedNsu_ID, nsu_id) && strcmp(storedPassword, password) == 0) {
            loginSuccessful = 1; // User logged in
            break;
        }
    }

    fclose(usersFile);

    if (loginSuccessful) {
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Incorrect password.\n");
        return 0;
    }
}
