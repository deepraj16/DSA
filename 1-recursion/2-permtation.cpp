#include<bits/stdc++.h> 
using namespace std ;

void solve(vector<int> a,int index,vector<vector<int>>&ans){

        if(index >=a.size()){
            ans.push_back(a);
            return ;
        }
        
        for(int i=index;i<a.size();i++){
                swap(a[index],a[i]);
                solve(a,index+1,ans);
                //backtrking 
                swap(a[index],a[i]);
        }
}
int main(){
    vector<int>nums={1,2,3};
    int index=0;
    vector<vector<int>>ans;
    string output;
    solve(nums,index,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
