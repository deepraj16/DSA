#include<bits/stdc++.h>
using namespace std ; 
vector<int> solve(vector<int>nums){
    stack<int> s; 
    vector<int>ans=nums;
    s.push(-1);
   for(int i=nums.size()-1 ;i>=0 ; i--){
    
    while(nums[i]<s.top()){
        s.pop();
    }
    ans[i]=s.top(); 
    s.push(nums[i]);
   }
  
   return ans;


}
int main(){
    vector<int> nums={2,1,4,3};
    vector<int> ans=solve(nums);
    for(int i=0;i<4;i++){
        cout<<ans[i]<<" ";
    }
}
