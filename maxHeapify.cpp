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
        // root is largest
        return;
    }
    else {
        swap(a[i], a[large]);
        algo(a, large, n);
    }
}
int main() {
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    algo(a, 1, n);
    cout << "Array after maxHeapify: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
