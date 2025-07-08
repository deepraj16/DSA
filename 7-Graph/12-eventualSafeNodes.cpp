class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&visted,vector<int>&path,vector<int>&check,int node){
        visted[node]=1;
        path[node]=1; 
        check[node]=0; 
        for(auto i : graph[node]){
            if(!visted[i]){
                if( dfs(graph,visted,path,check,i)){
                    return true;
                }
            }
            else if(path[i]){
                return true;
            }
        }
        check[node]=1;
        path[node]=0; 
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visted(n,0); 
        vector<int>path(n,0);
        vector<int>check(n,0); 
        vector<int>ans; 

        for(int i=0;i<n;i++){
            if(!visted[i]){
               dfs(graph,visted,path,check,i);
            }
        }

        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
