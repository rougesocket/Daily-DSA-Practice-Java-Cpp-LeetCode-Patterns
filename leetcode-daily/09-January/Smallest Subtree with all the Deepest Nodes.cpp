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
    vector<TreeNode*> leavesdeep(TreeNode* root){
        
        queue<TreeNode* > q;
        
        q.push(root);
        
        while(true){
            int sz = q.size();
            vector<TreeNode*> row;
            for(int i=0;i<sz;i++){
                root = q.front();
                q.pop();
                row.push_back(root);
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
            if(q.empty())return row;
        }
    }
    TreeNode* LCA(TreeNode* root,TreeNode* m,TreeNode* n){
        
        if(root==NULL || m==root || n==root)return root;
        
        TreeNode* l = LCA(root->left,m,n);
        TreeNode* r = LCA(root->right,m,n);
        
        if(!l)return r;
        else if(!r)return l;
        else return root;
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        if(root==NULL)return NULL;
        
        vector<TreeNode*> leaf = leavesdeep(root);
        
        TreeNode* ans = leaf[0];
        ans = LCA(root,ans,leaf[leaf.size()-1]);
        
        return ans;
    }
};