class Solution {
public:
        bool dfs(vector<vector<int>>& adj , vector<int>& color, vector<int>& visited, int node, int c) {
        visited[node] = 1; 

        if(color[node] != -1){
            return color[node] == c; 
        }

        color[node] = c;

        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(!dfs(adj, color, visited, neighbor, 1 - c)) {
                    return false;
                }
            }
            else if(color[neighbor] == c) {
                return false; 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n); 
        for(int u = 0; u < n; u++) {
            for(int v : graph[u]) {
                adj[u].push_back(v);
            }
        }

        vector<int>color(n,-1); 
        vector<int>visted(n,0);
        for(int i=0;i<n;i++){
            if(!visted[i]){
            if(!dfs(adj,color,visted,i,1)){
                return false;
            }}

        }
        return true;
    }
};
