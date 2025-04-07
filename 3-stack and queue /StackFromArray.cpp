#include<bits/stdc++.h> 
using namespace std;
// desing a stack for STl 
class Stack{
    private : 
    int top; 
    int * arr; 
    int size; 
    public:

    Stack(int size){
        this->size=size; 
        top=-1; 
        arr =new int[size];
    }

    void push(int data){
        if(size-top>1){
            top++; 
            arr[top]=data;
        }
        else{
            cout<<"Stack is Overflow"<<endl;
        }
    }

    void pop(){
        if(top>-1){
            top--;
        }
        else{
            cout<<"Stack is Underflow"<<endl;
        }
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false ;
        }
    }

    int peek(){
        if(top!=-1){
            return arr[top];
        }
        return -1;
    }
};

void print(Stack s1){
    while(!s1.isempty()){
        cout<<s1.peek()<< " "; 
        s1.pop();
    }
}

int main(){


    Stack s1(5);
    s1.pop(); 
    s1.push(34);
    cout<<s1.peek()<<endl;
    s1.push(24);
    cout<<s1.peek()<<endl;
    s1.push(54);
    cout<<s1.peek()<<endl;
    s1.push(64);
    cout<<s1.peek()<<endl;
    s1.push(74);
    cout<<s1.peek()<<endl;
    s1.push(722);
    cout<<s1.peek()<<endl;

    print(s1);

    s1.pop();

    if(s1.isempty()){
        cout<<"Stack is empty";
    }


    return 0;
}
