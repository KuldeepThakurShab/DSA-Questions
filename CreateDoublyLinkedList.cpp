#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int value){   
        prev=NULL;       
        data=value;   
        next=NULL;     
    }
};

void insert_at_tail(node* &head, node*&tail,int value){  
    node*n = new node(value);
    if(head==NULL){
       head=n;
       tail=n;
        return;
    }
    node* temp=head;  
    while(temp->next){  //temp->next!=NULL
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
 
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" --> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;      // declaring an empty doubly linked list
    node*tail=NULL;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int data; cin>>data;
        insert_at_tail(head,tail,data);
    }
     display(head);
    return 0;
}