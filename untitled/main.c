#include <stdio.h>
#include <stdlib.h>

#define WORD_MAX 9

char* compressedString(char* word) {
    int word_len = 0;
    while (word[word_len] != '\0') word_len++;

    char* result = (char*)malloc(2*word_len+2);
    int result_len = 0;
    int word_count = 0;

    for(int i = 0; i < word_len; i++) {
        if (word_count == 0) {
            word_count = 1;
        }
        else {
            if (word[i] == word[i-1]) {
                if (word_count  == 9) {
                    word_count = 1;
                    result[result_len++] = '9';
                    result[result_len++] = word[i];
                }
                else
                    word_count++;
            }
            else {
                result[result_len++] = word_count +'0';
                result[result_len++] = word[i-1];
                word_count = 1;
            }
        }
    }
    result[result_len++] = word_count +'0';
    result[result_len++] = word[word_len-1];
    result[result_len] = '\0';
    return result;
}

int main(void) {
    printf("Hello, World!\n");
    printf("\nResult = %s",compressedString("aaaaaaaaaaaaaabb"));
    return 0;
}
