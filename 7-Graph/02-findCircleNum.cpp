class Solution {
public:
     void solve(vector<vector<int>>& adj,vector<int>&visted,int nodes){
        visted[nodes]=1;
        for(auto i  :adj[nodes]){
            if(!visted[i]){
                solve(adj,visted,i);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n, 0);
        vector<vector<int>>adj(n); 
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
           if(visited[i]==0){
             solve(adj,visited,i);
            count++;
           }
           
        }
       return count;
    }
};
