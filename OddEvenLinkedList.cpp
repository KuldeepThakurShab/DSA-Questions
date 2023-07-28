#include<iostream>
using namespace std;
class node{
     public:
     int data;
     node* next;
     //constructor
     node(int d){
        data=d;
        next=NULL;
     }
};
void insertattail(node*&head,node*&tail,int data){
    node*n=new node(data);
    if(head==NULL) {
        head=n;
        tail=n;
        return ;
    }
    tail->next=n;
    tail=n;

}
node*odd_evenlinkedlist(node*head){
        //no node present
        if(head==NULL) return NULL;
        //single or double node present
        if(head->next==NULL|| head->next->next==NULL) return head;
        node*odd=head;
        node*even=head->next;
        node*evenfinal=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenfinal;
        return head;
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
    odd_evenlinkedlist(head);
    cout<<"Odd Even Linked List is :"<<endl;
    print(head);
    return 0;
}