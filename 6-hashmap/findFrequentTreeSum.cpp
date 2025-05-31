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
    unordered_map<int,int> s ; 
    int max_feq=0; 

    int solve(TreeNode* root){
        if (!root) return 0;  

        int left=solve(root->left); 
        int right=solve(root->right); 

        int sum=left +right + root->val ; 
        s[sum]++ ;
        max_feq=max(max_feq,s[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans; 
        solve(root);
        for(auto& [sum , feq] : s){
            if(feq==max_feq){
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
