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
    int minVal(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }

        if(root->val ==key){

            // delection code 
            // zero child 
            if(root->left ==NULL and root->right==NULL){
                delete root;
                return NULL;
            }

            else if(root->left !=NULL and root->right==NULL){
                TreeNode* temp=root->left;
                delete root; 
                return temp; 

            }

             else if(root->left ==NULL and root->right!=NULL){
                TreeNode* temp=root->right;
                delete root; 
                return temp; 

            }

            //2 child case 
            else if(root->left !=NULL and root->right!=NULL){
                int mini=minVal(root->right);

                // repalce value 
                root->val=mini;
                // 
               root->right= deleteNode(root->right,mini);
                    return root;

            }



        }
        else if(root->val >key){
            root->left=deleteNode(root->left,key); 
            return root;
        }
        else{
             root->right=deleteNode(root->right,key); 
            return root;
        }
        return root;
    }
    
};
