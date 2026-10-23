#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};
void bubble_sort(Node* head,int n){
    for(int i=n-1;i>0;i--){
        int didSwap=0;
        Node* p=head;
        for(int j=0;j<=i-1;j++){
            if(p->data>p->next->data){
                int temp=p->next->data;
                p->next->data=p->data;
                p->data=temp;
                didSwap=1;
            }
            p=p->next;
        }
        if(didSwap==0)
            break;
        cout<<"runs\n";
    }
}
int main(){
    int n,x;
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        cin>>x;
        if(head==nullptr)
            head=tail=new Node(x);
        else{
            tail->next=new Node(x);
            tail=tail->next;
        }
    }
    bubble_sort(head,n);
    Node* p=head;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
