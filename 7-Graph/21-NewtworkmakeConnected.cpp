class DisjointSet {
   
public:
     vector<int> parent, rank;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]); // Path compression
    }
    void UnionBase(int u, int v) {
        int up_u = findParent(u);
        int up_v = findParent(v);
        if (up_u == up_v)
            return;

        if (rank[up_u] < rank[up_v]) {
            parent[up_u] = up_v;
        } else if (rank[up_u] > rank[up_v]) {
            parent[up_v] = up_u;
        } else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n); 
        int cnt=0;
        for(auto it:connections){
            int u=it[0]; 
            int v=it[1]; 

            if(ds.findParent(u) !=ds.findParent(v)){
               ds.UnionBase(u,v);
            }
            else{
                cnt++;
            }
        }
        int cnCom=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cnCom++;
            }
        }
        
        return  cnt >=cnCom-1 ? cnCom-1 :-1;
        
    }
};
