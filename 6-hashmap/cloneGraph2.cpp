#include <unordered_map>
#include <vector>
using namespace std;

// Definition is already provided, just filling in the solution
class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // If the node has already been cloned, return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a new node with the same value
        Node* clone = new Node(node->val);
        visited[node] = clone; // Mark this node as cloned

        // Clone all neighbors recursively
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
