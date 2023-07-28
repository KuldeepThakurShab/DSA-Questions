#include<iostream>
#include<vector>
#include <bits/stdc++.h>
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
vector<node*>splitListToParts(node* head, int k) {
        vector<node*> res;
        node* temp = head;
        int l=0;
        while(temp){
            temp = temp->next;
            l++;
        }
        int element = l/k;
        int rem = l%k;
        node*ans=head;
        temp = ans;
        while(k--){
            if(element==0 && rem==0){
                res.push_back(NULL);
                continue;
            }
            int count=0;
            while(count<element)
            {
                count++;
                if(count<element){
                    temp = temp->next;
                }
            }
            if(rem>0){
                if(element>0){
                    temp = temp->next;
            }
                rem--;  
            }
            node*curr = temp->next;
            temp->next = NULL;
            res.push_back(ans);
            ans =  curr;
            temp = ans;
        }
        
        return res;
    }
 void display(node* head){
    while (head->next != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "\n";
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
    int k; cin>>k;
    vector<node*>v=splitListToParts(head,k);
     for (int i = 0; i < v.size(); i++) {
        display(v[i]);
    }
    return 0;
}