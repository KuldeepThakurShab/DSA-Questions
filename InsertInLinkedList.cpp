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

void insertatfront(node*&head,node*&tail,int data){
    node*n=new node (data);
    if(head==NULL){
        head=n;
        tail=n;
        return;
    }
    else {
        n->next=head;
        head=n;
    }
}
void insertattail(node*&head, node*&tail, int data){
    node*n=new node (data);
    if(head==NULL){
        head=n;
        tail=n;
        return;
    }
    else {
        tail->next=n;
        tail=n;
    }
}
// int lengthofll(node*head){
//     node*temp=head;
//     int count=0;
//     while(temp!=NULL){
//         count++;
//         temp=temp->next;
//     }
//     return count;
// }
int lengthofll(node*head){
     if(head==NULL) return 0;
     return 1+lengthofll(head->next);
}

void insertatanypostion(node*&head, node*&tail, int data , int pos){
    //case 1 pos=0
    if(pos==0){
        insertatfront(head,tail,data);
    }
    else if(pos>=lengthofll(head)){
        insertattail(head,tail,data);
    }
    else {
        node*temp=head;
        node*n=new node(data); 
        for(int jump=1; jump<=pos-1; jump++){
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;

    }
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
      node *head=NULL;
      node *tail=NULL;
    insertatfront(head,tail,90);
    insertatfront(head,tail,63);
    insertatfront(head,tail,20);
    insertatfront(head,tail,100);
   // print(head);
    insertattail(head,tail,79);
    insertattail(head,tail,49);
   print(head);
    insertatanypostion(head,tail,89,3);
    print(head);
    return 0;
}