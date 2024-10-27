#include <cstdlib>
#include <stdio.h>
#include <string.h>
bool isEqual(char str1[], char str2[2]) {
    int idex = 0;
    while (str1[idex] !=0) {
        if (str1[idex]!=str2[idex]) return false;
        idex++;
    }
    return true;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    // Sort based on string length
    for (int i = 0; i < strsSize - 1; i++) {
        for (int j = i + 1; j < strsSize; j++) {
            if (strlen(strs[i]) > strlen(strs[j])) {
                char* temp = strs[i];
                strs[i] = strs[j];
                strs[j] = temp;
            }
        }
    }

    char* prefix = (char*)malloc(strlen(strs[0]) + 1);
    int len = 0;

    for (int i = 0; i < strlen(strs[0]); i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                prefix[len] = '\0';
                return prefix;
            }
        }
        prefix[len++] = strs[0][i];
    }

    prefix[len] = '\0';
    return prefix;
}


int main() {
    char** strs[][] = {"floer","flow","flight"};
    longestCommonPrefix(strs,3);

    return 0;
}