#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* makeFancyString(char* s) {
    char *str = (char*) malloc(sizeof(char)*(strlen(s)+1));
    int len = 0;
    int s_len = 0;
    int consecutive_char = 0;
    while (s[s_len]!=0) {
        if (len>0 && s[s_len] == str[len-1]) {
            consecutive_char++;
            if (consecutive_char <=2) {
                //str  = (char*)realloc(str, len+1);
                str[len++] = s[s_len++];
            }else
                s_len++;
        }
        else {
            consecutive_char = 1;
            //str  = (char*)realloc(str, len+1);
            str[len++] = s[s_len++];
        }
    }
    str[len] = 0;
    return str;
}


int main(void) {
    printf("Hello, World!\n");
    printf("\n%s",makeFancyString("aabaabaabaa"));
    return 0;
}
