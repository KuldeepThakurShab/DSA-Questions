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
void insertattail(node*&head, node*&tail, int data){
    node*n=new node(data);
    if(head==NULL){
        head=n;
        tail=n;
        return ;
    }
    else{
        tail->next=n;
        tail=n;
    }
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
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
     node*h1=NULL;
     node*t1=NULL;
     node*h2=NULL;
     node*t2=NULL;
     int n,m,data;
     cin>>n;
     for(int i=0; i<n; i++){
        cin>>data;
        insertattail(h1,t1,data);
     }
     cin>>m;
     for(int i=0; i<m ; i++){
        cin>>data;
        insertattail(h2,t2,data);
     }
     node*finalans=merge_linkedlist(h1,h2);
     cout<<"LINKED LIST AFTER MERGE :"<<endl;
     print(finalans);
    return 0;
}