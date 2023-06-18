#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login() {
    FILE* file = fopen("login_details.txt", "r");
    
        return 0;
    

    char username[100];
    char id[10];
    char password[32];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your NSU id: ");
    scanf("%s", id);
    printf("Enter your password: ");
    scanf("%s", password);

    char file_username[100];
    char file_id[10];
    char file_password[32];

    while (fscanf(file, "%s %s", file_username, file_id, file_password) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(id, file_id) == 0 && strcmp(password, file_password) == 0) {
            fclose(file);
            return 1; // Successful login
        }
    }

    fclose(file);
    return 0; // Invalid login
}
