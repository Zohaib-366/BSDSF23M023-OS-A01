#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/myfilefunctions.h"

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file) return -1; // error

    int c;
    *lines = *words = *chars = 0;
    int in_word = 0;

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if (c == ' ' || c == '\n' || c == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            (*words)++;
        }
    }

    return 0; // success
}


int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;

    char line[1024];
    int count = 0;
    int capacity = 10;

    *matches = (char**)malloc(capacity * sizeof(char*));
    if (!*matches) return -1;

    rewind(fp);  // Ensure we start from the beginning

    while (fgets(line, sizeof(line), fp)) {
    	if (strstr(line, search_str)) {  // Line contains search string
            if (count >= capacity) {
                capacity *= 2;
                *matches = (char**)realloc(*matches, capacity * sizeof(char*));
                if (!*matches) return -1;
            }
            (*matches)[count] = strdup(line);  // Allocate and copy line
            if (!(*matches)[count]) return -1;
            count++;
        }
    }
    return count;
}

