class DisjoinSet {
public: 
    vector<int> rank, parents;

    DisjoinSet(int n) {
        rank.resize(n+1, 0); 
        parents.resize(n+1);
        for(int i = 0; i <= n; i++) parents[i] = i;
    }

    int Parent(int v) {
        if (v == parents[v]) return v;
        return parents[v] = Parent(parents[v]); // Path compression
    }

    void UnionOpreation(int u, int v) {
        int up_u = Parent(u); 
        int up_v = Parent(v); 
        if (up_v == up_u) return;

        if (rank[up_u] < rank[up_v]) {
            parents[up_u] = up_v;
        } else if (rank[up_u] > rank[up_v]) {
            parents[up_v] = up_u;
        } else {
            parents[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp ; 
        int n=accounts.size(); 
        DisjoinSet ds(n); 
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                  ds.UnionOpreation(i,mp[mail]);
                }
            }
        }

        unordered_map<int,vector<string>>merge; 
        for(auto [mail , index] : mp){
            int parent = ds.Parent(index);
            merge[parent].push_back(mail);
        }

        
     
         vector<vector<string>> res;
        for (auto& [index, emails] : merge) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[index][0]); // name
            res.push_back(emails);
        }

        return res;
    }
};
