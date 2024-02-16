#include <stdio.h>

int removeDuplicates(int nums[], int numsSize) {
   
    if (numsSize <= 1) {
        return numsSize;
    }
    
    int current = 0;
    int nextUnique = 1;

    while (nextUnique < numsSize) {
        if (nums[current] != nums[nextUnique]) {
            nums[++current] = nums[nextUnique];
        }
        nextUnique++;
    }
    
    return current + 1;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newLength = removeDuplicates(nums, numsSize);

    printf("Array with duplicates removed:\n");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
