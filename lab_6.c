#include<stdio.h>
#include<stdlib.h>

int lis_dp(int arr[], int n) {
    int *lis = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < lis[i]) {
            max = lis[i];
        }
    }
    free(lis);
    return max;
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of LIS is %d\n", lis_dp(arr, n));
    return -1;
}

