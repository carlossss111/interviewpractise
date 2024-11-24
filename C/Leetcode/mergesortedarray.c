#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* output = nums1;
    int insert_pos = nums1Size - 1;
    
    n--; m--;
    
    while(n >= 0){
       // Finished with nums 1
       if(m == -1){
           nums1[insert_pos] = nums2[n];
           n--;
       }
       // Nums 1 is greater
       else if(nums1[m] > nums2[n]) {
           nums1[insert_pos] = nums1[m];
           m--;
       }
       // Nums 2 is greater
       else{
           nums1[insert_pos] = nums2[n];
           n--;
       }
       insert_pos--;
    }
    // Finished with nums 2
    
    // This is a pretty cool solution
}

int main(int argc, char** argv){
    int nums1[] = {1,2,3,0,0,0};
    int m = 3;
    int nums2[] = {2,5,6};
    int n = 3;
    int expected[] = {1,2,2,3,5,6};

    merge(nums1, sizeof(nums1) / sizeof(int), m, nums2, sizeof(nums2) / sizeof(int), n);

    printf("Expected: %d, %d, %d, %d, %d, %d\n", expected[0], expected[1], expected[2], expected[3], expected[4], expected[5]);
    printf("Actual:   %d, %d, %d, %d, %d, %d\n", nums1[0], nums1[1], nums1[2], nums1[3], nums1[4], nums1[5]);
    return 0;
}

