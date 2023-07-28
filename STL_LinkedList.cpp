#include<iostream>
#include<list>  //cpp reference list for google this
using namespace std;
int main(){
    list<int>l;
    l.push_back(2);
    l.push_back(4);
    l.push_front(15);
    l.push_front(14);
    l.push_back(98);
    l.push_back(32);
    l.pop_back();
    l.pop_front();
    cout<<l.front()<<endl;
    cout<<l.back()<<endl;
    cout<<*l.begin()<<endl;  //l.begin gives addres of first node on derefering it gives data of that node
    //print
    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++){
        cout<<*it<<"->";
    }
    cout<<endl;
    //print ->> BY using For Each loop
    for(auto node: l){
        cout<<node<<"-->";
    }
    cout<<endl;
    return 0;
}