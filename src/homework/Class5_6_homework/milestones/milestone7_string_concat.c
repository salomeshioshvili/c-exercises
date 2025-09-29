#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat_strings(const char* str1, const char* str2) {
    if (!str1 || !str2) return NULL;
    
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    char* result = malloc(len1 + len2 + 1);
    if (!result) return NULL;
    
    strcpy(result, str1);
    strcat(result, str2);
    
    return result;
}

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    
    char* result = concat_strings(str1, str2);
    if (result) {
        printf("'%s' + '%s' = '%s'\n", str1, str2, result);
        free(result);
    } else {
        printf("Failed to concatenate strings\n");
    }
    
    return 0;
}
