#include<iostream>
using namespace std;
class node{
     public:
     int data ;
     node*next;
     //constructor
     node(int d){
        data=d;
        next=NULL;
     }
};
void insertattail(node*&head,node*&tail, int data){
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
// bool search_key(node*head,int key){
//     //base case
//     if(head==NULL) return false;
//     //recursive case
//     if(head->data==key) return true;
//     return search_key(head->next,key);
// }
//itratively
bool search_key(node*head,int key){
    while(head!=NULL){
        if(head->data==key) return true;
        head=head->next;
    }
    return false;
}
int main(){
    node*head=NULL;
    node*tail=NULL;
    int n,data,key;
    cin>>n>>key;
    for(int i=0; i<n; i++){
        cin>>data;
        insertattail(head,tail,data);
    }
   if( search_key(head,key)) cout<<"key is present"<<endl;
   else cout<<"key is not present"<<endl;
    return 0;
}