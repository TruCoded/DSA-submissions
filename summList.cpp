Sum of any 2 num in arr using list:-
#include <bits/stdc++.h>
using namespace std;
void printsum(int arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int left = 0, right = n - 1;
        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) {
                cout << arr[i];
                break;
            }
            else if (sum < arr[i]) {
                left++;
            }
            else {
                right--;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printsum(arr, n);
    return 0;
}