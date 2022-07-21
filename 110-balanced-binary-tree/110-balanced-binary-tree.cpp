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
    bool func(TreeNode* node, int &h) {
        if(node == NULL) return true;
        int lh = 0;
        int rh = 0;
        
        int l = func(node->left, lh);
        int r = func(node->right, rh);
        
        h = lh > rh ? lh : rh;
        h += 1;
        
        if(abs(lh-rh) > 1) return false;
        
        return l&r;
        
    }
    bool isBalanced(TreeNode* root) {
        int h = 1;
        return func(root,h);
    }
};