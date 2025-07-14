class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& r : roads) {
            int u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

      
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
           auto [dis , node]=pq.top(); 
            pq.pop();
           for(auto it: adj[node]){
            int nei=it.first; 
            int nei_dis=it.second; 
            long long new_dist=nei_dis + dis ; 
            if(new_dist <  dist[nei]){
                dist[nei]=new_dist; 
                pq.push({new_dist,nei}); 
                ways[nei]=ways[node];
            }
            else if(new_dist == dist[nei]){
                ways[nei]=(ways[node]+ways[nei])%MOD;
            }
           }
        }
      
        return ways[n - 1];
    }
};
