#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    //constructor
    node(int d){
        data=d;
        next=NULL;
    }
};
void insertattail(node*&head,node*&tail,int data){
    node*n=new node(data);
    if(head==NULL){
        head=n;
        tail=n;
        return;
    }
    else{
        tail->next=n;
        tail=n;
    }
}
node*mid(node*head){
    node*slow=head;
    node*fast=head->next;
   while(fast!=NULL && fast->next!=NULL){
             slow=slow->next;
           fast=fast->next->next;
   }  
   return slow;
}
node*merge_linkedlist(node*h1,node*h2){
    //base case
     if(h1==NULL) return h2;
     if(h2==NULL) return h1;
    //recursive case
    node*newhead;
    if(h1->data<h2->data){ 
        newhead=h1;
        newhead->next=merge_linkedlist(h1->next,h2);
    }
    else {
        newhead=h2;
        newhead->next=merge_linkedlist(h1,h2->next);
    }
    return newhead;
}
node*mergesort(node*head){
    //base case
    if(head==NULL || head->next==NULL) return head;
    //recursive case
    node*m=mid(head);
    node*left=head;
    node*right=m->next;
    m->next=NULL;
    left= mergesort(left);
    right=mergesort(right);
   node*result= merge_linkedlist(left,right);
   return result;
}

void print (node*head){
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
        if(head!=NULL) cout<<"-->";
    }
}
int main(){
    node*head=NULL;
    node*tail=NULL;
    int n,data;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        insertattail(head,tail,data);
    }
    node*fans=mergesort(head);
    cout<<"LINKED LIST AFTER MERGESORT:"<<endl;
    print ( fans);
    return 0;
}