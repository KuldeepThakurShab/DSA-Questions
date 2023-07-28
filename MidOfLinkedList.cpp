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
void insert_attail(node*&head,node*&tail,int data){
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
int lengthofll(node*head){
     if(head==NULL) return 0;
     return 1+lengthofll(head->next);
}
int mid_oflinkedlist(node*head){
    node*slow=head;
    node*fast=head->next;
   while(fast!=NULL && fast->next!=NULL){
             slow=slow->next;
           fast=fast->next->next;
   }  
   return slow->data;
}
 
int main(){
    node*head=NULL;
    node*tail=NULL;
    int n,data;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        insert_attail(head,tail,data);
    }
    cout<<mid_oflinkedlist(head)<<endl;

    return 0;
}
/*
Mid of linked list without using slow and fast as well length
Initialize the mid element as head and initialize a counter as 0. 
Traverse the list from the head, while traversing increment the counter and change mid to mid->next whenever the counter is odd. 
So the mid will move only half of the total length of the list. 

--->>CODE
void midoflinkedlist(node*head){
    int count=0;
    node*mid=head;
    while(head){
        if(count%2!=0) mid=mid->next;

        ++count;
        head=head->next;

    }
     if(mid!=NULL){
            cout<<mid->data<<endl;
        }
}
*/