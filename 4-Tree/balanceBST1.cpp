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
    void solve(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);

    }
    TreeNode* helper(vector<int>&ans,int s,int end)
   {
        if(s>end){
            return NULL ;
        }
        int mid=(s+end)/2;
        TreeNode* root = new TreeNode(ans[mid]);
       root->left= helper(ans,s,mid-1);
       root->right= helper(ans,mid+1,end);
        return root;
   }  
  TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans ; 
        solve(root,ans);
        int n=ans.size();
      TreeNode* newroot = helper(ans, 0, n - 1);
        return newroot;
    }
};
