#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    int length = 0;
    while (s[length] != '\0') { // count until null terminator
        length++;
    }
    return length;
}

int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') { // copy each character
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // add null terminator
    return i;       // return number of characters copied
}

int mystrncpy(char* dest, const char* src, int n) {
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {  // pad remaining with '\0'
        dest[i] = '\0';
    }
    // Ensure null-termination just in case
    if (n > 0) dest[n] = '\0';
    return i; // number of characters copied
}

int mystrcat(char* dest, const char* src) {
    int i = 0;
    int j = 0;

    // Find the end of dest string
    while (dest[i] != '\0') {
        i++;
    }

    // Copy src to the end of dest
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0'; // null-terminate
    return i;       // return total length of new string
}

