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
/*
int length(node*head){
    if(head==NULL) return 0;
    return 1+length(head->next);
}
void* kthelement(node*head,int k){
    node*front=head;
	if(k>length(head)) return NULL;
     for(int i=0; i<length(head)-k; i++){
          front=front->next;
     }
        cout<<front->data<<endl;
}
*/
void print(node*head){
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
        if( head  ) //head!=NULL
      cout <<"-->";
    }
    cout<<endl;
}
void kthelement(node*head,int k){
    node*front=head;
    node*back=head;
    for(int i=0; i<k; i++){
        if(front==NULL) {
            cout<<k<<"is greter than the number of nodes in linked list"<<endl;
            return;
        }
        front=front->next;
    }
    while(front!=NULL){
        back=back->next;
        front =front->next;
    }
    cout<<"Kth element from last is: "<<endl<<back->data;
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
    int k; cin>>k;
    kthelement(head,k);
    return 0;
}
/* 2nd way
#include <iostream>
using namespace std;
class node{
   public:
   int data;
   node*next;
   node(int d){
       data=d;
       next=NULL;
   }

};
void insertattail(node*&head, node*&tail, int data){
    node*n=new node(data);
    if(!head){
        head=n;
        tail=n;
        return ;
    }
    else {
        tail->next=n;
        tail=n;
    }
}
void print(node*head){
    while(head!=NULL){ //head
        cout<<head->data;
        head=head->next;
        if( head  )
      cout <<"-->";
    }
    cout<<endl;
}
int kthnodefromlast(node*head,int k){
    node*temp=head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    if(k>l) return -1;
    int x=l-k;
    temp=head;
    while(x--){
        temp=temp->next;
    }
  //return temp ? temp->data:-1;
  if(temp) return temp->data;
  else return -1;
}
int main() {
    node*head=NULL;
    node*tail=NULL;
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int data; cin>>data;
        insertattail(head,tail,data);
    }
    print (head);
    int k; cin>>k;
    cout<<kthnodefromlast(head,k);
   return 0;
}
*/