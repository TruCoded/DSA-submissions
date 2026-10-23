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
void selection_sort(Node* head){
    for(Node* i=head;i!=nullptr && i->next!=nullptr;i=i->next){
        Node* mini=i;
        for(Node* j=i;j!=nullptr;j=j->next){
            if(j->data<mini->data)
                mini=j;
        }
        swap(i->data,mini->data);
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
    selection_sort(head);
    Node* p=head;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
