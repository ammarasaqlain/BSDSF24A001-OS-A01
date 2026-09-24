// File: src/myfilefunctions.c
#include "../include/myfilefunctions.h"
#include <stdlib.h>
#include <string.h>

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL) return 1;
    *lines = 0; *words = 0; *chars = 0;
    int ch;
    int in_word = 0;
    
    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;
        if (ch == '\n') (*lines)++;
        
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            (*words)++;
        }
    }
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL) return 1;
    char buffer[1024];
    int count = 0;
    *matches = NULL;
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, search_str) != NULL) {
            *matches = realloc(*matches, sizeof(char*) * (count + 1));
            (*matches)[count] = malloc(strlen(buffer) + 1);
            strcpy((*matches)[count], buffer);
            count++;
        }
    }
    return count;
}
