#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int Partition(vector<int>& arr,int low,int high){
        int pivot=arr[low];
        int start=low;
        int end=high;
        while(start<end){
            while(start<=high && arr[start]<=pivot)
                start++;
            while(arr[end]>pivot)
                end--;
            if(start<end)
                swap(arr[start],arr[end]);
        }
        swap(arr[low],arr[end]);
        return end;
    }
    void qs(vector<int>& arr,int low,int high){
        if(low<high){
            int pIndex=Partition(arr,low,high);
            qs(arr,low,pIndex-1);
            qs(arr,pIndex+1,high);
        }
    }
    vector<int> quickSort(vector<int>& arr){
        qs(arr,0,arr.size()-1);
        return arr;
    }
};
int main(){
    vector<int> arr={10,7,8,9,1,5};
    Solution sol;
    sol.quickSort(arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}
