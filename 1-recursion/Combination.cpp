#include<bits/stdc++.h>
using namespace std; 

//why i am not solving the problem for me 
int sum_of_array(vector<int>output){
    int sum=0;
    for(int i=0;i<output.size();i++){
            sum=sum+output[i];
    }
    return sum;
}
void solve(vector<int>nums ,int traget,vector<vector<int>>&ans,vector<int>output,int index){

        if(index>=nums.size()){
            return ;
        }
        if(traget==sum_of_array(output)){
            ans.push_back(output); 
            return ;
        }
        // not indelt 
        solve(nums,traget,ans,output,index+1);

        //include 
        output.push_back(nums[index]) ; 
        solve(nums,traget,ans,output,index+1);

}

int main(){
    
    vector<int> nums={2,3,4,5,1,2,1,1,1};
    int traget=4;
    vector<vector<int>>ans; 
    vector<int>output ; 
    int index=0;
    int sum_of_array=0;
    solve(nums,traget,ans,output,index); 

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}
