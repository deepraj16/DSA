#include<bits/stdc++.h> 
using namespace std ; 

void solve(string nums,string output , int index,vector<string>& ans){
            if(index >=nums.size()){
                // if (output == ""){
                //         return ;
                // }
                if(output.size() == 2  ){
                    ans.push_back(output);
                    
                }

                
                    
                    return ;
                
               
            }

            //exclude 
            solve(nums,output,index+1,ans);

            //!SECTION 
            int element = nums[index]; 
            output.push_back(element);
            solve(nums,output,index+1,ans);
}

int main(){
    string nums="abc";
    vector<string>ans ;
    string output; 
    int index =0 ; 
    solve(nums,output,index,ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j< ans[i].size();j++){
                cout<<ans[i][j]<< " ";
        }
        cout<<1<<endl;
    }
    return 0;
}
