#include<bits/stdc++.h>
using namespace std ; 

void sorted(stack<int>&s,int element){
    if(s.empty()){
        s.push(element);
        return ;
    }
    if(s.top()<element){
        s.push(element); 
        return;
    }
    int data=s.top(); 
    s.pop(); 

    sorted(s,element);
    s.push(data);
}

void sort_a_stack(stack<int>&s){
    if(s.empty()){
        return ;
    }
    int element=s.top();
    s.pop(); 
    sort_a_stack(s);
    sorted(s,element);
}

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" "; 
        s.pop();
    }
}

int main(){
    stack<int>s;
    s.push(341);
    s.push(340);
    s.push(36); // middle element for given stack so 
    s.push(371);
    s.push(-4);
   
    print(s);
    cout<<s.top();
    cout<<endl;
    sort_a_stack(s);
    print(s);

}
