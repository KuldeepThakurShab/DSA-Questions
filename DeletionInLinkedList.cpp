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
void insert_attail(node*&head, node*&tail, int data){
           node*n=new node(data);
           if(head==NULL){
            head=n;
            tail=n;
            return ;
           }
           else {
            tail->next=n;
            tail=n;
           }
}
int lengthofll(node*head){
     if(head==NULL) return 0;
     return 1+lengthofll(head->next);
}

void delet_atfront(node*&head,node*&tail){
    //case->> ll is empety
    if(head==NULL) return ;
    //case->> one node present
    else if(head->next==NULL){
        delete head;
        head=NULL;
        tail=NULL;
    }
    //case ->> multiple nodes 
    else {
        node*temp=head;
        head=head->next;
        delete temp;
        temp->next=NULL;
    }
}
void delet_attail(node*&head, node*&tail){
        if(head==NULL) return ;
    //case->> one node present
    else if(head->next==NULL){
        delete head;
        head=NULL;
        tail=NULL;
    }
    //case->> multiple nodes
    else{
        node*temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;
    }
}
void deleteatanypos(node*&head,node*&tail,int pos){
    if(pos==1) delet_atfront(head,tail);
    else if(pos>=lengthofll(head)) delet_attail(head,tail);
    else{
        node*temp=head;
        node*prev;
        for(int jump=1; jump<=pos-1;jump++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
    }
}
void print(node*head){
    node*temp=head;
  while(temp!=NULL){
    cout<<temp->data;
    temp=temp->next;
    if(temp!=NULL) cout<<"-->";
  }
    cout<<endl;
}
int main(){
    node *head=NULL;
    node*tail=NULL;
    int n,data; cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        insert_attail(head,tail,data);
    }
//    print (head);
//    cout<<"linked list after deletion at front"<<endl;
//    delet_atfront(head,tail); 
//    print (head);
//    cout<<"linked list after deletion at tail "<<endl;
//    delet_attail(head,tail);
//    print (head);
   int pos ; cin>>pos;
   cout<<"linked list after deletion at particular postion "<<endl;
   deleteatanypos(head,tail,pos);
   print(head);
    return 0;
}