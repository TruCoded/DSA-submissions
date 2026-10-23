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
void insertion_sort(Node* head){
    if(head==nullptr)
        return;
    for(Node* i=head->next;i!=nullptr;i=i->next){
        for(Node* j=head;j!=i;j=j->next){
            if(j->data>i->data)
                swap(j->data,i->data);
        }
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
    insertion_sort(head);
    Node* p=head;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }

    return 0;
}
