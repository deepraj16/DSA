class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n=colors.size();
        vector<vector<int>> adj(colors.size()); 
        vector<int>indgree(colors.size(),0);
        for(auto it:edges){
            int u=it[0],v=it[1]; 
            adj[u].push_back(v);
            indgree[v]++;
        }
        queue<int>q;
        vector<vector<int> >dp(colors.size(),vector<int>(26,0)); 
        for(int i=0;i<n;i++){
            if(indgree[i]==0){
                q.push(i);
            }
        }
        int process=0; 
        int maxColorCount=0;
        while(!q.empty()){
            int u=q.front(); 
            q.pop(); 
            process++;
            int col =colors[u]-'a'; 
            dp[u][col]++; 
            maxColorCount=max(maxColorCount,dp[u][col]);

            for(auto it : adj[u]){
                for(int i=0;i<26;i++){
                    dp[it][i]=max(dp[u][i],dp[it][i]);
                }
                indgree[it]--; 
                if(indgree[it]==0) q.push(it);
            }
            
        }
    return process == n? maxColorCount : -1;
        
    }
};
