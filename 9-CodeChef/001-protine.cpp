#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; 
	cin>>t; 
	
	while(t--){
	    int store=0,n,k; 
	    cin>>n>>k; 
	    bool flag =true;
	
	    vector<int>day(n,0);
	    for(int i=0;i<n;i++){
	        int g; 
	        cin>>g;
	        day[i]=g;
	    }
	    
	    for(int i =0;i<n;i++){
	        int sub = day[i] - k ; 
	        //cout<<sub<<" "<<k<<" "<<store<<endl;
	        if(store+sub <0 && sub<0){
	            cout<<"NO "<<i+1<<endl;
	            flag=false;
	            break;
	        }
	        
	            store+=sub;
	        
	    }
	    
	    if(flag){
	        cout<<"YES"<<endl;
	    }
	}
    
}
