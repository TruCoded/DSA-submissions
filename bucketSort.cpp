#include <bits/stdc++.h> 
using namespace std;
int main() {
  int arr[] = {30, 40, 10, 80, 5, 12, 70}; // I/P array
  int k = 4; // no.of buckets
  int maxElement = arr[0];
  int arrSize = sizeof(arr) / sizeof(arr[0]); // get arr size
  // to find max element in the array
  for (int i = 1; i < arrSize; i++) {
    maxElement = max(maxElement, arr[i]);
  }
  maxElement++; 
  vector<int> buckets[k];
  // Place array elements into appropriate buckets
  for (int i = 0; i < arrSize; i++) {
    int bucketIndex = (k * arr[i]) / maxElement; 
    buckets[bucketIndex].push_back(arr[i]);      
  }
  for (int i = 0; i < k; i++) {
    sort(buckets[i].begin(), buckets[i].end());
  }
  // Merge all sorted buckets back into original array
  int ind = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < buckets[i].size(); j++) {
      arr[ind++] = buckets[i][j];
    }
  }
  // Output sorted array
  for (int i = 0; i < arrSize; i++)
    cout << arr[i] << " ";
  return 0;
}
