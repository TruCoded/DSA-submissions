#include<iostream>
using namespace std;
class Solution{
    public:
    int linearSearch(int arr[],int n,int key){
        for(int i=0;i<n;i++){
            if(arr[i]==key){
                return i;
            }
        }
        return -1;
    }
void insert(int arr[],int &n,int key,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            for(int j=n;j>i+1;j--){
                arr[j]=arr[j-1];
            }
            arr[i+1]=x;
            n++;
            break;
        }
    }
}
void Delete(int arr[],int &n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            for(int j=i;j<n-1;j++){
                arr[j]=arr[j+1];
            }
            n--;
            break;
        }
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
    Solution s;
    int arr[10]={1,4,6,7,8};
    int key,x;
    int n=5;
    cout<<"Enter key to search:";
    cin>>key;
    int num=s.linearSearch(arr,n,key);
    if(num!=-1){
        cout<<"Element found at index"<<num<<endl;
    }
    else{
        cout<<"Element is not found"<<endl;
    }
    cout<<"Enter key and element to insert:";
    cin>>key>>x;
    s.insert(arr,n,key,x);
    cout<<"Elements being displayed:";
    s.display(arr,n);
    cout<<endl;
    cout<<"Enter key to delete:";
    cin>>key;
    s.Delete(arr,n,key);
    cout<<"Elements being displayed:";
    s.display(arr,n);
    cout<<endl;
    return 0;
}
