#include <stdlib.h>

int string_length(char *string) {
    int length = 0;
    while (*string != '\0') {
        length++;
        string++;
    }
    return length;
}

void string_copy(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int string_compare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    return str1[i] - str2[i]; 
}                  

char* string_duplicate(char *string) {
    char *duplicate = malloc(string_length(string) + 1);
    string_copy(duplicate, string);
    return duplicate;
}