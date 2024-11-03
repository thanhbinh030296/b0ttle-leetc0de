#include <stdbool.h>
#include <stdio.h>

bool rotateString(char* s, char* goal) {
    int len_s = 0;
    int len_goal = 0;

    while (s[len_s]!=0) len_s++;
    while (goal[len_goal]!=0) len_goal++;

    if (len_s != len_goal) return false;

    // find
    for (int i = 0; i < len_s; i++) {

        if (goal[0] == s[i]) {
            //
            bool isFound = true;
            for (int j = 1; j < len_goal;j++) {
                if (i + j >= len_s) {
                    if (s[i +j -len_s]!=goal[j]) {
                        isFound = false;
                        break;
                    }
                }
                else if (s[i +j]!=goal[j]) {
                    isFound = false;
                    break;
                }
            }
            if (isFound) return true;
        }
    }
    return false;

}

int main(void)
{
    printf("\na = %d",true);
    printf("\ns = %d",rotateString("defdefdefabcabc","defdefabcabcdef"));
    return 0;
}
