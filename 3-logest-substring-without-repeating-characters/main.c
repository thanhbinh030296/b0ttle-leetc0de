#include <stdbool.h>
#include <stdio.h>


int lengthOfLongestSubstring(char* s) {
    int len = 0;
    while (s[len]!=0) len++;
    if (len==0) return 0;
    int idx = 0;
    int max_len = 1;
    int substring_len = 1;
    while (max_len < len-idx) {
        for (int i = idx + 1; i< len;i++) {
            bool isAddable=true;
            int chosen_idx = -1;
            for (int j = idx; j < i; j++) {
                if (s[j] == s[i]) {
                    isAddable=false;
                    chosen_idx=j;
                    break;
                }
            }
            if (isAddable) {
                substring_len++;
                max_len = substring_len > max_len ? substring_len : max_len;
            }
            else {
                idx =chosen_idx+1;
                substring_len = 1;
                break;
            }
        }
    }
    return max_len;
}
int main(void) {
    printf("\nd = %d\n",lengthOfLongestSubstring("dvdf"));
    printf("Hello, World!\n");
    return 0;
}
