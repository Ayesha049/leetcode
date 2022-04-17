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
    TreeNode * ans = NULL;
    TreeNode * t = NULL;
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);
        TreeNode * node = new TreeNode(root->val);
        if(ans == NULL) {
            ans = node;
            t = ans;
        }
        else {
            t->right = node;
            t=t->right;
        }
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};