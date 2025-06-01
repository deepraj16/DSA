class Solution {
public:
     void dfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&visied,int n,int m){
        if(i<0 || j<0 || j>=m || i>=n || visied[i][j]==1 || grid[i][j]==0){
            return ;
        }
        visied[i][j]=1; 
        int dx[4]={0,0,-1,1}; 
        int dy[4]={-1,1,0,0}; 
        for(int k=0;k<4;k++){
            dfs(i+dx[k],j+dy[k],grid,visied,n,m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        vector<vector<int>>visted(n,vector<int>(m,0));
         
         for(int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(0,j,grid,visted,n,m);
            if(grid[n-1][j]==1) dfs(n-1,j,grid,visted,n,m);
         }
        
           for(int j=0;j<n;j++){
            if(grid[j][0]==1) dfs(j,0,grid,visted,n,m);
            if(grid[j][m-1]==1) dfs(j,m-1,grid,visted,n,m);
         }
         
         int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visted[i][j]==0 and grid[i][j]==1){
                  c++;
                }
            }
        }
        return c;
    }
};
