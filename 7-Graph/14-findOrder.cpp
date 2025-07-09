class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adj(numCourses);
        vector<int>indegre(numCourses,0);
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1]; 
            adj[v].push_back(u);
            indegre[u]++;
        }
        // vector<int>visted(numCourses,0);
       //  vector<int>indegre(numCourses,0); 
        
        queue<int>q; 
        for(int i=0;i<numCourses;i++){
            if(indegre[i]==0){
                q.push(i);
            }
        }

        vector<int>ans; 
        while(!q.empty()){
            int node=q.front(); 
            q.pop(); 
            ans.push_back(node);
            for(auto it:adj[node]){
                indegre[it]--; 
                if(indegre[it]==0){
                    q.push(it);
                }
            }
        }

        //by khans method 
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};
