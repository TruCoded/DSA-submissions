#include <bits/stdc++.h>
using namespace std;
void algo(int a[], int i, int n) {
    int left = 2 * i;
    int large = i;
    int right = 2 * i + 1;
    if (left <= n && a[left] > a[large])
        large = left;
    if (right <= n && a[right] > a[large])
        large = right;
    if (i == large) {
        return;
    }
    else {
        swap(a[i], a[large]);
        algo(a, large, n);
    }
}
void BuildHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--)
        algo(a, i, n);
}
void heapsort(int a[], int n) {
    BuildHeap(a, n);
    for (int i = n; i >= 2; i--) {
        swap(a[1], a[i]);
        algo(a, 1, i - 1);
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n + 1];
    cout << "Enter array elements: ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    heapsort(a, n);
    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}