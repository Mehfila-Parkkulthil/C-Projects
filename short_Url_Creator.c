#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//function generateShortCode
void generateShortCode(char code[], int length) {
    char charset[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    int charsetSize = strlen(charset);

    for (int i = 0; i < length; i++) {
        int index = rand() % charsetSize;
        code[i] = charset[index];
    }
    code[length] = '\0';     // null-terminate the string
}

int main() {
    char longURL[500];
    char shortCode[7];       // 6 chars + '\0'

    printf("Enter the long URL: ");
    fgets(longURL, sizeof(longURL), stdin);


    // remove newline from fgets
    longURL[strcspn(longURL, "\n")] = '\0';

    srand(time(0));
    generateShortCode(shortCode, 6);

    printf("\n");
    printf("Processing............ \n");
    printf("\n");
    printf("Original URL : %s\n", longURL);

    printf("\n");
    printf("Short URL    : https://aieracode.ly/%s\n", shortCode);

    printf("\n");
    return 0;
}
