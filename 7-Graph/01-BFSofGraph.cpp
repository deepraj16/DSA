class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int>ans; 
        int n=adj.size();
        int visted[n]={0}; 
        queue<int>q; 
        q.push(0); 
        visted[0]=1; 
        while(!q.empty()){
            int node=q.front(); 
            q.pop(); 
            
            ans.push_back(node);
                for(auto j:adj[node]){
                    if(visted[j]!=1){
                        visted[j]=1;
                        q.push(j);
                    
                }
            }
        }
        return ans;
    }
};
