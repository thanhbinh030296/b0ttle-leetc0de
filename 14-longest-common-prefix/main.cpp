#include <cstdlib>
#include <stdio.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize < 1) return "";
    int shortest_len_idx = -1;
    int shortest_len = 99999;
    int len = 0;
    for (int i =0; i< strsSize; i++) {
        len = 0;
        while(strs[i][len]!=0)
            len++ ;
        if (shortest_len >len) {
            shortest_len = len;
            shortest_len_idx = i;
        }
    }
    char* result = (char*)malloc(shortest_len+1);
    len = 0;
    printf("\nidx = %d",shortest_len_idx);
    // prefix (di tu indx =0)
    for (int j = 0; j < shortest_len;j++)
    {
        for (int i = 0; i<strsSize; i++)
        {
            if (i == shortest_len_idx) continue;
            if (strs[i][j] != strs[shortest_len_idx][j]){
                result[len] = '\0';
                return result;
            }
        }
        result[len++] = strs[shortest_len_idx][j];
    }
    result[len] = 0;
    return result;
}


int main() {
    char** strs[][] = {"floer","flow","flight"};
    //longestCommonPrefix(strs,3);

    return 0;
}