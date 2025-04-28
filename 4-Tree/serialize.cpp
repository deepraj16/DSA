/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<string, int> subtreeCount;
    vector<TreeNode*> result;

    string serialize(TreeNode* node) {
        if (!node) return "#";

        string serial = to_string(node->val) + "," + 
                        serialize(node->left) + "," + 
                        serialize(node->right);
        
        subtreeCount[serial]++;
        if (subtreeCount[serial] == 2) {
            result.push_back(node);  
        }

        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};
