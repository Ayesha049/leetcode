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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        dq.push_back(root);
        bool reverse = true;
        while(!dq.empty()) {
            int size = dq.size();
            vector<int>v;
            for(int i=0;i<size;i++) {
                if(reverse) {
                    TreeNode* node = dq.front();
                    v.push_back(node->val);
                    dq.pop_front();
                    if(node->left != NULL) {
                        dq.push_back(node->left);
                    }
                    if(node->right != NULL) {
                        dq.push_back(node->right);
                    }
                } else {
                    TreeNode* node = dq.back();
                    v.push_back(node->val);
                    dq.pop_back();
                    if(node->right != NULL) {
                        dq.push_front(node->right);
                    }
                    if(node->left != NULL) {
                        dq.push_front(node->left);
                    }
                }
            }
            ans.push_back(v);
            reverse = !reverse;
        }
        return ans;
    }
};