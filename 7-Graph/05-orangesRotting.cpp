class Solution {
public:
bool is_fresh(vector<vector<int>>& grid,vector<vector<bool>>visted,int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<n && j<m && grid[i][j]==1 && !visted[i][j]  );
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        
        //fist check all postion of the rotten orange
      vector<vector<bool>> visted(n, vector<bool>(m, false));
        queue<pair<int ,pair<int,int>>>q ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    visted[i][j]=true;
                }
            }
        }
    
        int dx[4]={-1,1,0,0}; 
        int dy[4]={0,0,-1,1};
        int time=1;
        int ans=0;
        
        while(!q.empty()){
            
             auto [time, pos] = q.front();
            q.pop();

            int i = pos.first;
            int j = pos.second;
            ans = max(ans, time);
            
            for(int k=0;k<4;k++){
                if(is_fresh(grid,visted,i+dx[k],j+dy[k],m,n)){
                    q.push({time+1,{i+dx[k],j+dy[k]}});
                    visted[i+dx[k]][j+dy[k]]= true;
                    grid[i+dx[k]][j+dy[k]]= 2;
                    
                }
            }
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                  return -1;
                }
                
            }
        }

return ans;
        
    }
};
