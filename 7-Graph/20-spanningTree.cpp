#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;

public:
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
        } 
        else if (rank[up_u] > rank[up_v]) {
            parent[up_v] = up_u;
        } else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<tuple<int, int, int>> edges; // (weight, u, v)

        
        for (int u = 0; u < V; ++u) {
            for (auto& it : adj[u]) {
                int v = it[0];
                int wt = it[1];
                if (u < v) { 
                    edges.push_back(make_tuple(wt, u, v));
                }
            }
        }

       
        sort(edges.begin(), edges.end());

        
        DisjointSet ds(V);
        int mst_weight = 0;

        for (auto& edge : edges) {
            int wt = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);

            if (ds.findParent(u) != ds.findParent(v)) {
                mst_weight += wt;
                ds.UnionBase(u, v);
            }
        }

        return mst_weight;
    }
};
