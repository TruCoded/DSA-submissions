#include<iostream>
using namespace std;
int Partition(int arr[],int i,int j){
    int pivot=arr[i];
    int start=i,end=j;
    while(start<end){
        while(start<=j && arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(arr[start],arr[end]);
    }
    swap(arr[i],arr[end]);
    return end;
}
void Selectk(int arr[],int low,int high,int k){
    while(low<=high){
       int pivotIndx=Partition(arr,low,high);
        if(pivotIndx==k)
            return;
        else if(k<pivotIndx)
            high=pivotIndx-1;
        else
            low=pivotIndx+1;
    }
}
int main(){
    int arr[]={3,2,10,5,4,7,8,9,1,6,15,11};
    int n=sizeof(arr)/sizeof(int);
    int k=8;
    Selectk(arr,0,n-1,k-1);
    cout<<"8 smallest elements: ";
    for(int i=0;i<k;i++)
        cout<<arr[i]<<" ";
    return 0;
}
