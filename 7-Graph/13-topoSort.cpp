class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V,0);
        for(int i=0;i<V;i++){
            int u=edges[i][0]; 
            int v=edges[i][1]; 
            adj.push_back(i);
        }
        vector<int>dqueue(V,0); 
        for(auto i:edges){
            dqueue[i[0]]++;
        }
        
        queue<int>q; 
        for(int i=0;i<V;i++){
            if(dqueue[i]==0){
                q.push(i);
            }
        }
        
        // khan
        vector<int> topo;
        while(q.empty()){
            int node=q.front(); 
            q.pop();
            topo.push_back(node)
            for(auto it: adj[node]){
                dqueue[it]--; 
                if(dqueue[it]==0){
                    q.push(it);
                }
            }
        }
        
        return topo;
        
    }
};
