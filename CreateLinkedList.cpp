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

int main(){
     node n1(5),n2=10;
     n1.next=&n2;
     cout<<"data of n1 "<<n1.data<<endl;
     cout<<"data of n2 "<<(*n1.next).data<<endl;
     cout<<"data of n2 "<<(n1.next)->data<<endl;
     node *n3=new node(15);
     cout<<"data of n3 "<<n3->data;
    return 0;
}