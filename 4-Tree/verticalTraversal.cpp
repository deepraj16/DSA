class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        map<int, map<int, vector<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front(); q.pop();
            TreeNode* node = temp.first;
            int col = temp.second.first;
            int row = temp.second.second;

            m[col][row].push_back(node->val);

            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }

        for (auto& col : m) {
            vector<int> col_nodes;
            for (auto& row : col.second) {
                vector<int> temp = row.second;
                sort(temp.begin(), temp.end());
                col_nodes.insert(col_nodes.end(), temp.begin(), temp.end());
            }
            ans.push_back(col_nodes);
        }

        return ans;
    }
};
