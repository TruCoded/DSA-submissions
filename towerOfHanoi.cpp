#include <bits/stdc++.h>
using namespace std;
void TOH(int n, char F, char U, char T) {
if(n == 1) {
        cout << "Move disk 1 from " << F << " to " << T << endl;
        return;
    }
    TOH(n-1, F, T, U);
    cout << "Move disk " << n << " from " << F << " to " << T << endl;
    TOH(n-1, U, F, T);
}
int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    TOH(n, 'A', 'B', 'C');
    return 0;
}
