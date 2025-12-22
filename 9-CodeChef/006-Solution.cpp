class Disjoin{
        public : 
        vector<int>parent ,rank; 
        
        Disjoin(int n){
            parent.resize(n); 
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i; 
                rank[i]=1;
            }
        }
        int find_par(int node){
            if(parent[node]== node){
                return node;
            }
            return parent[node]=find_par(parent[node]);
        }

        void union_by_rank(int u,int v){
            int u_par=find_par(u); 
            int v_par=find_par(v); 

            if(u_par == v_par){
                return ;
            }
            if(rank[u_par]> rank[v_par]){
                parent[v_par]=u_par;
            }
           else  if(rank[u_par]< rank[v_par]){
                parent[u_par]=v_par;
            }
            else{
                 parent[v_par]=u_par;
                 rank[u_par]+=1;
            }
        }
       
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        // vector<vector<int>adj;
         Disjoin ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    ds.union_by_rank(i,j);
                }
            }
        }
    int ans=ds.number_parent(); 
    return ans;
        
    }
};
