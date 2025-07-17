class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // kans algorthim for solving  

        vector<vector<int>> adj(numCourses); 
        vector<int>indgree(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indgree[it[0]]+=1;
        }
        queue<int>q; 
        int n=numCourses;
        for(int i=0;i<n;i++){
            if(indgree[i]==0){
                q.push(i);
            }

        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front(); 
            q.pop(); 
            ans.push_back(node);
            for(auto it:adj[node]){
                indgree[it]--;
                if(indgree[it]==0){
                    q.push(it);
                }
            }

        }
        //sort(ans.begin(),ans.end());
        if(n!=ans.size()) return {};
        return ans;
    }
};
