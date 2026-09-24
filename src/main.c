// File: src/main.c
#include <stdio.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    
    char my_word[50] = "Hello";
    int length = mystrlen(my_word);
    printf("The word Hello has %d letters.\n", length);
    
    mystrcat(my_word, " World");
    printf("Glued together: %s\n", my_word);

    printf("\n--- Testing File Functions ---\n");
    
    FILE* fp = fopen("REPORT.md", "r");
    if (fp != NULL) {
        int lines, words, chars;
        wordCount(fp, &lines, &words, &chars);
        printf("REPORT.md has %d lines, %d words, %d chars.\n", lines, words, chars);
        fclose(fp);
    } else {
        printf("Could not open the file.\n");
    }
    
    return 0;
}
