class Solution {
  public:
    vector<vector<int>> create_adj(vector<vector<int>>&edges,int V){
        int n=edges.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<n;i++){
            int u=edges[i][0]; 
            int v=edges[i][1]; 
            adj[u].push_back(v); 
            adj[v].push_back(u);
        }
       
       return adj; 
    }
    
    bool BFS(vector<vector<int>>& adj,vector<bool>&visited,int src){
         queue<pair<int,int>>q;
            q.push({src,-1}); 
            visited[src]=true;
            while(!q.empty()){
                int node =q.front().first;
                int parent=q.front().second; 
                q.pop();
                for(auto i:adj[node]){
                    if(!visited[i]){
                        visited[i]=true; 
                        q.push({i,node});
                    }
                    else if(parent!=i){
                        return true;
                    }
                }
            }
            return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        
         vector<vector<int>>adj=create_adj(edges,V);
         int n=V;
         vector<bool>visited(n,false);
         for(int i=0;i<n;i++){
             if(!visited[i]){
                 if(BFS(adj,visited,i)){
                     return true;
                 }
             }
         }
         return false;
           
    }
};
