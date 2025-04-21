#include<stdio.h>
#include<limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int kadane(int arr[], int n) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < n; i++) {
        max_so_far = max(max_so_far, max_ending_here + arr[i]);
        max_ending_here = max(max_ending_here + arr[i], 0);
    }
    return max_so_far;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("Maximum sum of subarray is %d\n", kadane(arr, sizeof(arr) / sizeof(arr[0])));
    return 0;
}