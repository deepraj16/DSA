#include<bits/stdc++.h>
using namespace std ; 

bool say(string& d,int i,int j){
        if(i>j){
                return true ;
        }
        if(d[i]!=d[j]){
            return false;
        }
        
       i++;
       j--;
       return say(d,i,j);
        
}

int main(){
    string d="aabbaa";
  cout<< say(d,0,d.size()-1);
   
}
