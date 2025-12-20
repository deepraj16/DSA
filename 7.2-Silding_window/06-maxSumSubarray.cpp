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

