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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left == NULL && right == NULL) return root->val == targetSum;
        return hasPathSum(left, targetSum - root->val) || hasPathSum(right, targetSum - root->val);
    }
};