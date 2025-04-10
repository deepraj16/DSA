#include<bits/stdc++.h>
using namespace std ; 

void insert_at_butthom(stack<int>&s , int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int e=s.top(); 
    s.pop(); 
    insert_at_butthom(s,element); 
    s.push(e);
}
void reves(stack<int>&s){
    // base case is  
    if(s.empty()){
        return ;
    }
    int elemet=s.top(); 
    s.pop(); 
    reves(s);
    insert_at_butthom(s,elemet);
}

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" "; 
        s.pop();
    }
}

int main(){
    stack<int>s;
    s.push(34);
    s.push(35);
    s.push(36); // middle element for given stack so 
    s.push(37);
    s.push(38);
    int element =3 ; 
    insert_at_butthom(s,element);
    print(s);
    cout<<s.top();

    reves(s);
    cout<<endl;
    print(s);

}
