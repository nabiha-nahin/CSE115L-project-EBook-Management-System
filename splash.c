#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displaySplashScreen() {

    FILE* file = fopen("splash.txt", "r");

    char character;
    while ((character = fgetc(file)) != EOF) {
        putchar(character);

    }

     fclose(file);
     printf("\n");
    // Wait for 3 seconds
    sleep(3);
}
