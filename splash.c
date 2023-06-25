#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "splash.h"

void displaySplashScreen() {

    FILE* file = fopen("splash.txt", "r");

    char character;
    while ((character = fgetc(file)) != EOF) {
        putchar(character);

    }

     fclose(file);
     printf("\n");
    // Wait for 5 seconds
    sleep(5);
}
