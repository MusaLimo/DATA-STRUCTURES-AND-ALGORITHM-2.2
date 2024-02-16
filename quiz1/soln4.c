#include <stdio.h>

int findSingle(int nums[], int numsSize) {
    int result = 0;
    
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    
    return result;
}

int main() {
    int nums[] = {4, 1, 2, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int singleElement = findSingle(nums, numsSize);
    
    printf("The single element that appears only once: %d\n", singleElement);
    
    return 0;
}
