#include<bits/stdc++.h>
using namespace std;
int recur(int u){
   if(u==0 or u==1){
    return 1;
   }
   return u * recur(u-1);
}

int main(){
    cout<<recur(5);
    cout<<"heallo world";
}