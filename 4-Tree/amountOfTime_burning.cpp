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

void mapping_parent(TreeNode*root ,map<TreeNode*,TreeNode*>&parent,int start,TreeNode* &mainnode){
        queue<TreeNode*>q;
        q.push(root); 
        parent[root]==NULL;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front(); 
                q.pop(); 
                if(temp->val==start){
                    mainnode=temp;
                }
                if(temp->left!=NULL){
                    q.push(temp->left); 
                    parent[temp->left]=temp; 
                }
                if(temp->right!=NULL){
                    q.push(temp->right); 
                    parent[temp->right]=temp; 
                }
            }
        }
    }
int mapping_parent( map<TreeNode*,TreeNode*>&parent ,TreeNode* mainnode)   {
            map<TreeNode*,bool>visted; 
            queue<TreeNode*>q; 
            q.push(mainnode);
            visted[mainnode]=true;

            int ans=0;
            while(!q.empty()){
                int n=q.size(); 
                bool flag=false;
                for(int i=0;i<n;i++){
                TreeNode* temp=q.front(); 
                q.pop(); 
                if(!visted[parent[temp]] and parent[temp] ){
                    q.push(parent[temp]);
                    visted[parent[temp]]=true;
                    flag=true;
                }
                if(temp->left!=NULL and !visted[temp->left]){
                     q.push(temp->left);
                    visted[temp->left]=true;
                    flag=true;
                }
                if(temp->right!=NULL and !visted[temp->right]){
                     q.push(temp->right);
                    visted[temp->right]=true;
                    flag=true;
                }
               
               
                }
                 if(flag==true){
                    ans++;
                }
                 
            }
            return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>parent; 
        TreeNode* mainnode; 
        mapping_parent(root,parent,start,mainnode);

        //working calulating the time to burn the tree 
        int ans=mapping_parent(parent,mainnode);
        return ans;
    }
};
