class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        
        // Calculate indegree correctly
        for(int i = 0; i < V; i++){
            for(auto neighbor : adj[i]){
                indegree[neighbor]++;
            }
        }
        
        queue<int> q; 
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // Kahn's algorithm
        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); 
            q.pop();
            topo.push_back(node);
            
            for(auto neighbor : adj[node]){
                indegree[neighbor]--; 
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        
        // Check if topological sort is possible (no cycle)
        if(topo.size() == V){
            return topo;
        }
        
        return {}; // Cycle detected
    }
    
    string findOrder(vector<string> &words) {
        // Find all unique characters
        set<char> charSet; 
        for(auto word : words){
            for(auto ch : word){
                charSet.insert(ch);
            }
        }
        
        // Create character to index mapping
        vector<char> indexToChar(charSet.begin(), charSet.end());
        unordered_map<char, int> charToIndex;
        for(int i = 0; i < indexToChar.size(); i++){
            charToIndex[indexToChar[i]] = i;
        }
        
        int n = charSet.size();
        vector<vector<int>> adj(n); 
        
        
        for(int i = 0; i < words.size() - 1; i++){
            string word1 = words[i]; 
            string word2 = words[i + 1]; 
            int minLen = min(word1.size(), word2.size()); 
            
            bool foundDiff = false;
            for(int k = 0; k < minLen; k++){
                if(word1[k] != word2[k]){
                    adj[charToIndex[word1[k]]].push_back(charToIndex[word2[k]]);
                    foundDiff = true;
                    break; 
                }
            }
            
           
            if(!foundDiff && word1.size() > word2.size()){
                return ""; 
            }
        }
        
        vector<int> order = topoSort(n, adj);
        if(order.empty()){
            return ""; // Cycle detected
        }
        
        string result = "";
        for(int idx : order){
            result += indexToChar[idx];
        }
        
        return result;
    }
};
