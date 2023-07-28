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
bool cyclicdetection(node*head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
void createcycle(node*head,node*tail,int postion){
    for(int i=0; i<postion-1; i++){
        head=head->next;
    }
    tail->next=head; 
}
void breakcycle(node*head){
    //step1->> cycle is present or not
    node*slow=head;
    node*fast=head;
    node*prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)  break;
    }
      slow=head;
      while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
        prev=prev->next;
      }
      prev->next=NULL;
}
void print(node*head){
  while(head!=NULL){
     cout<<head->data;
     head=head->next;
     if(head!=NULL){
        cout<<"-->";
     }
  }
  cout<<endl;
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
    print(head);
    if(cyclicdetection(head)){
        cout<<"LINKED LIST IS CYCLIC "<<endl;
    }
    else cout<<"LINKED LIST IS NOT CYCLIC"<<endl;
    int postion;
    cin>>postion;
    createcycle(head,tail,postion);
    //print(head);
    breakcycle(head);
    print(head);
    return 0;
}   