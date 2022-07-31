#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    int numsSize = nums1Size + nums2Size;
    int * nums = malloc(numsSize * sizeof(int));
    do {
        if (i1 < nums1Size) {
            if (i2 < nums2Size) {
                if (nums1[i1] < nums2[i2]) {
                    nums[i] = nums1[i1];
                    i++;
                    i1++;
                }
                else if (nums2[i2] < nums1[i1]) {
                    nums[i] = nums2[i2];
                    i++;
                    i2++;
                }
                else {
                    nums[i] = nums1[i1];
                    i++;
                    i1++;
                    nums[i] = nums2[i2];
                    i++;
                    i2++;
                }
            }
            else {
                nums[i] = nums1[i1];
                i++;
                i1++;
            }
        } 
        
        if (i2 < nums2Size) {
            if (i1 < nums1Size) {
                if (nums2[i2] < nums1[i1]) {
                    nums[i] = nums2[i2];
                    i++;
                    i2++;
                }
                else if (nums1[i1] < nums2[i2]) {
                    nums[i] = nums1[i1];
                    i++;
                    i1++;
                }
                else {
                    nums[i] = nums1[i1];
                    i++;
                    i1++;
                    nums[i] = nums2[i2];
                    i++;
                    i2++;                   
                }
            }
            else {
                nums[i] = nums2[i2];
                i++;
                i2++;
            }
        } 
    } while (i < numsSize);

    // DEBUG
    // for (int i = 0; i < numsSize; i++) {
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");

    double median;
    int m = numsSize / 2;
    if (numsSize % 2) {
        median = (double)nums[m];
    }
    else {
        median = ((double)nums[m-1] + (double)nums[m]) / 2.0; 
    }

    free(nums);

    return median;
}

int main() {
    int nums1[] = {0,0};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {0,0};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    printf("%f", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
    return 0;
}