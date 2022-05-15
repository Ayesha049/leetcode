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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        int deep = 0;
        queue<pair<TreeNode*,int>>q;
        if(root == NULL) return ans;
        q.push(make_pair(root,1));
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int d = q.front().second;
            q.pop();
            if(d==deep) ans+=node->val;
            if(d>deep) {
                deep = d;
                ans = node->val;
            }
            if(node->left != NULL) q.push(make_pair(node->left,d+1));
            if(node->right != NULL) q.push(make_pair(node->right,d+1));
        }
        return ans;
    }
};