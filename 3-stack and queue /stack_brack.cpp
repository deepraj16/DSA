#include<bits/stdc++.h>
using namespace std;

bool isreduant(string a,stack<char>s){
    for(int i=0;i<a.length();i++){
        char ch=a[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='/' || ch=='*'){
                s.push(ch);
        }
        else{
            if(ch==')'){
                bool isredunt=true;
                    while(s.top()!='(')
                    {
                        char top=s.top();
                        if( top=='+' || top=='-' || top=='/' || top=='*'){
                            isredunt=false;
                           return false;
                    }
                    s.pop();
                    }
        
                        return true;
                        s.pop();
                    }
                }
        }
    }
    return false;
}
int main(){
    string a="((a+c)*b)";
    stack<char>s; 
    cout<<isreduant(a,s);
    return 0;
}
