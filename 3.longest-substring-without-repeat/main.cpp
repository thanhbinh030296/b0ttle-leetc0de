#include <stdio.h>
#include <stdlib.h>


int lengthOfLongestSubstring(char *s) {
    struct CharToken {
        char value;
        struct CharToken *next;
    };

    struct CharToken *start_token = (struct CharToken *) malloc(sizeof(struct CharToken));

    int char_idx = 0;
    bool isStart = true;
    int len, max_len;
    len = max_len = 0;
    while (s[char_idx] != '\0') {
        if (isStart) {
            isStart = false;
            start_token->value = s[char_idx];
            start_token->next = NULL;
            char_idx++;

            len = max_len = 1;

            continue;
        }

        // check the char is exist on list
        CharToken *curr_token = start_token;
        //CharToken* prev_token = curr_token;
        while (curr_token->value != s[char_idx] && curr_token->next != NULL) {
            //prev_token = curr_token;
            curr_token = curr_token->next;
        }
        // check curr_token is the last?
        if (curr_token->value == s[char_idx]) {
            if (curr_token->next == NULL) {
                //this token is at the end of array
                start_token = curr_token;
                len = 1;
            } else {
                start_token = curr_token->next;
                len = 0;

                while (curr_token->next != NULL) {
                    // get longest len
                    len++;
                    curr_token = curr_token->next;
                }
            }
        } else {
            // tuc la deo trong day
            len++;
            while (curr_token->next != NULL) {
                curr_token = curr_token->next;
            }
            struct CharToken *new_token = (struct CharToken *) malloc(sizeof(struct CharToken));
            new_token->value = s[char_idx];
            new_token->next = NULL;
            curr_token->next = new_token;

            max_len = max_len < len ? len : max_len;
        }
        char_idx++;
    }
    return max_len;
}

int main() {
    lengthOfLongestSubstring("pwwkew");
    return 0;
}
