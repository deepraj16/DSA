#include<bits/stdc++.h> 
using namespace std ; 

bool issafe(vector<vector<int>> nums,vector<vector<int>> &visted,int x,int y){
        if((x>=0 and x<nums.size()) && (y>=0 and y<nums.size()) && (visted[x][y]==0 && nums[x][y]==1)){
          return true;
        }
        else{
          return false;
        }
}

void solve(vector<vector<int>> nums,vector<vector<int>> &visted,vector<string>&ans,int x,int y,string path){
      if(x==3 and y==3){
        ans.push_back(path);
        return ;
      }

      //Down 
      visted[x][y]=1;
        int newx=x+1; 
        int newy=y;
        if(issafe(nums,visted,newx,newy)){
          path.push_back('D');
          solve(nums,visted,ans,newx,newy,path);
          path.pop_back();
        }

          //left 
     
       newx=x; 
       newy=y-1;
      if(issafe(nums,visted,newx,newy)){
        path.push_back('L');
        solve(nums,visted,ans,newx,newy,path);
        path.pop_back();
      }

        //right
       newx=x; 
       newy=y+1;
      if(issafe(nums,visted,newx,newy)){
        path.push_back('R');
        solve(nums,visted,ans,newx,newy,path);
        path.pop_back();
      }

       newx=x-1; 
       newy=y;
      if(issafe(nums,visted,newx,newy)){
        path.push_back('U');
        solve(nums,visted,ans,newx,newy,path);
        path.pop_back();
      }


      visted[x][y]=0;
}

 
int main(){
    vector<vector<int>> nums={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<vector<int>> visted=nums; 
    vector<string> ans;
    vector<int>route;
    int scrx=0;
    int scry=0;
    //solve(nums,visted,ans,route);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
          visted[i][j]=0;    
        }
        }

        string path ="";

        solve(nums,visted,ans,scrx,scry,path);

        for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
            cout<<nums[i][j]<<" ";    
          }
          cout<<endl;
          }
          cout<<ans.size();
        for(int i=0;i<ans.size();i++){
          cout<<ans[i]<<endl;
        }
    return 0;
}
