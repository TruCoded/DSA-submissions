#include <bits/stdc++.h>
using namespace std;
void binSort(int arr[], int n) {
    int max = arr[0];
        for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int bin[max + 1] = {0};
    for (int i = 0; i < n; i++) {
        bin[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i <= max; i++) {
        while (bin[i] > 0) {
            arr[j] = i;
            j++;
            bin[i]--;
        }
    }
}
int main() {
    int arr[] = {3, 2, 10, 5, 4, 7, 8, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    binSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
