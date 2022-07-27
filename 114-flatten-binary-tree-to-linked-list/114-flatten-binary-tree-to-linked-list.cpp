/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,vector<TreeNode*> &v)
    {
        if(root==NULL) return;
        v.push_back(root);
        dfs(root->left,v);
        dfs(root->right,v);
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        dfs(root,v);
        if(v.size()<=1) return;
        for(int i=0;i<v.size()-1;i++)
        {
            v[i]->left = NULL;
            v[i]->right = v[i+1];
        }
        v.back()->left = NULL;
        v.back()->right = NULL;
    }
};