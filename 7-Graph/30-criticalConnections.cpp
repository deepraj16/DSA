#include <vector>
using namespace std;

class Solution {
public:
    int time = 0;

    void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& disc, vector<int>& low, vector<vector<int>>& result) {
        disc[node] = low[node] = ++time;

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;

            if (disc[neighbor] == -1) {
                dfs(neighbor, node, graph, disc, low, result);
                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > disc[node]) {
                    result.push_back({node, neighbor});
                }
            } else {
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> result;

        for (int i = 0; i < n; ++i) {
            if (disc[i] == -1) {
                dfs(i, -1, graph, disc, low, result);
            }
        }

        return result;
    }
};
