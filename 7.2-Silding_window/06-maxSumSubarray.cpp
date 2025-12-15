#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[], int n, int k) {
    if (n < k) return -1;

    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    for (int i = k; i < n; i++) {
        windowSum += arr[i];       // add next element
        windowSum -= arr[i - k];   // remove previous element
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Maximum sum: " << maxSumSubarray(arr, n, k);
    return 0;
}
