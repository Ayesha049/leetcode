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
    void dfs(vector<vector<int>> &ans, vector<int>&v, TreeNode* node, int target, int sum) {
        if(node==NULL) return;
        sum+=node->val;
        v.push_back(node->val);
        if(node->left == NULL && node->right==NULL && target==sum) {
            ans.push_back(v);
        }
        dfs(ans,v,node->left,target,sum);
        dfs(ans,v,node->right,target,sum);
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>v;
        dfs(ans,v,root,targetSum, 0);
        return ans;
    }
};