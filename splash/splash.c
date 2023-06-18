#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displaySplashScreen();

void displaySplashScreen() {

    FILE* file = fopen("splash.txt", "r");
    /* if (file == NULL) {
        printf("Error opening splash.txt\n");
        return;
    }*/

    char character;
    while ((character = fgetc(file)) != EOF) {
        putchar(character);

    }

     fclose(file);
    // Wait for 3 seconds
    clock_t start_time = clock();
    while (clock() < start_time + 5 * CLOCKS_PER_SEC)
        ;
}


int main(){

 displaySplashScreen();


/*
printf(" :::::::::             ::::::::      ::::::::    ::::::::   :::    :::       :::::   :::::     :::     ::::    :::     :::      ::::::::  :::::::::: :::::   ::::: :::::::::: ::::     :::  ::::::::::: \n");
printf(" :::                   :::    ::    :::    :::  :::    :::  :::   :::        :::::: ::::::   ::: :::   :::::   :::   ::: :::   :::    ::: :::        :::::: :::::: :::        :::::    :::      :::     \n");
printf(" :::                   :::    ::    :::    :::  :::    :::  :::  :::         ::: ::::: :::  :::   :::  ::::::  :::  :::   :::  :::   :::: :::        ::: ::::: ::: :::        ::::::   :::      :::     \n");
printf(" :::::::::    ----     ::::::::     :::    :::  :::    :::  :::::::          :::  :::  ::: ::::::::::: ::: ::: ::: ::::::::::: :::        ::::::::   :::  :::  ::: ::::::::   :::  ::: :::      :::     \n");
printf(" :::                   :::    ::    :::    :::  :::    :::  :::  :::         :::       ::: :::     ::: :::  :::::: :::     ::: :::   :::: :::        :::       ::: :::        :::   ::::::      :::     \n");
printf(" :::                   :::    ::    :::    :::  :::    :::  :::   :::        :::       ::: :::     ::: :::   ::::: :::     ::: :::    ::: :::        :::       ::: :::        :::    :::::      :::     \n");
printf(" :::::::::             ::::::::      ::::::::    ::::::::   :::    :::       :::       ::: :::     ::: :::    :::: :::     :::  ::::::::  :::::::::: :::       ::: :::::::::: :::     ::::      :::     \n");
*/

return 0;

}