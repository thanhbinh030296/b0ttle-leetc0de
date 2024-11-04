#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


vvoid merge(int* array, int start, int end) {
    if (start == end) return;
    int left = start;
    int right = (start+end)/2 +1;
    int *result = (int*)calloc(end-start + 1, sizeof(int));
    int idx =0;
    while (left <= (start + end)/2  || right <= end) {
        if (left <= (start + end)/2 && right <=  end) {
            if (array[left] < array[right]) {
                result[idx++] = array[left++];
            }
            else {
                //printf("%d  %d %d",idx,left, right);
                result[idx++] = array[right++];
            }
        }
        else if ( left <= (start + end)/2 ) {
            result[idx++] = array[left++];
        }
        else if (right <= end) {
            result[idx++] = array[right++];
        }
    }
    // re-allocate
    for (int i = start; i<= end; i++) {
        array[i] = result[i-start];
    }
    free(result);
}

void split(int* array, int start, int end) {
    if (start >= end - 1) {
        return ;
    }
    int middle = (start + end)/2;
    split(array, start, middle);
    split(array, middle +1, end);
    merge(array,start,middle);
    merge(array,middle+1,end);
    merge(array,start,end);
}

bool isGood(int* nums, int numsSize) {
    split(nums,0,numsSize-1);


    if (nums[numsSize-1]  !=numsSize-1) return false;

    if (nums[numsSize-1]  !=nums[numsSize-2]) return false;

    for (int i = numsSize - 3; i >=0; i--)
    {
        if (nums[i] == nums[i+1]) return false;
    }

    return true;
}

int main(void) {
    //int nums[] = {3, 4, 4, 1, 2, 1};
    int nums[] = { 3,3,3};
    printf("\ntrue = %d",true);
    printf("\nc = %d", isGood(nums,sizeof(nums)/sizeof(nums[0])));
    return 0;
}
