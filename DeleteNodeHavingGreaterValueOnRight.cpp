#include <iostream>
using namespace std;
class node{
     public:
     int data;
     node*next;
     node(int d){
         data =d;
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
void print(node*head){
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
        if( head != NULL)
      cout <<"-->";
    }
    cout<<endl;
}
node* reverse(node*head){
    node*curr=head;
    node*prev=NULL;
    node*n;
    while(curr){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    return prev;
}
node* deletegreater(node*head){
    head=reverse(head);
    node*curr=head;
    node*prev=head;
    int max=head->data;
    head=head->next;
    while(head){
        if(head->data>=max){
            max=head->data;
            prev=head;
            head=head->next;
        }
        else{
            prev->next=head->next;
            head=prev->next;
        }
    }
    head=reverse(curr);
    return head;
}
int main() {
    node*head=NULL;
    node*tail=NULL;
    int n,data;
    cin>>n;
    for(int i=0; i<n ;i++){
        cin>>data;
        insertattail(head,tail,data);
    }
   node*h1=deletegreater(head);
   print(h1);
    return 0;
}
/*   Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
*/