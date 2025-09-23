#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    
    printf("Testing mystrlen:\n");
    char str[] = "Hello, Neo!";
    printf("Length of '%s' = %d\n", str, mystrlen(str));

	printf("\nTesting mystrcpy:\n");
	char source[] = "Caption is here.";
	char destination[50];  // make sure it’s big enough
	mystrcpy(destination, source);
	printf("Copied string: '%s'\n", destination);

    printf("\nTesting mystrncpy:\n");
	char source2[] = "ZohaiB366";
	char destination2[20];
	mystrncpy(destination2, source2, 6); // copy first 5 chars
	printf("Partial copy: '%s'\n", destination2);

	printf("\nTesting mystrcat:\n");
	char str1[50] = "ZohaiB";
	char str2[] = "366";
	mystrcat(str1, str2);
	printf("Concatenated string: '%s'\n", str1);

	printf("\n--- Testing File Functions ---\n");

	printf("Testing wordCount:\n");
	FILE* fp = fopen("../test.txt", "r");
	if (fp) {
    int l, w, ch;
    wordCount(fp, &l, &w, &ch);
    printf("Lines: %d, Words: %d, Characters: %d\n", l, w, ch);
    fclose(fp);
	}
	else {
    printf("Failed to open file.\n");
	}

	printf("\nTesting mygrep:\n");
	fp = fopen("../test.txt", "r");
	if (fp) {
	    char **matches = NULL;
	    int count = mygrep(fp, "Neo", &matches);
	
	    if (count == -1) {
	        printf("Error in mygrep.\n");
    	} else {
        	printf("Found %d matches:\n", count);
        	for (int i = 0; i < count; i++) {
            	printf("%s", matches[i]);
            	free(matches[i]);  // free each line
        	}
        	free(matches);        // free the array itself
    	}
    	fclose(fp);
	} else {
    	printf("Failed to open file.\n");
	}
	
    return 0;
}

