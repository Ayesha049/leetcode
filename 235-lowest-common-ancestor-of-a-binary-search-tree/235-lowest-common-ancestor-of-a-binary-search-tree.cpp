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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* r) {
        if(p->val == r->val) return p;
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        if(root==NULL) return NULL;
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right != NULL) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        unordered_map<TreeNode*,bool>marked;
        while(p != NULL) {
            marked[p] = true;
            p = parent[p];
        }
        
        while(r != NULL) {
            if(marked[r]) return r;
            r = parent[r];
        }
        
        return NULL;
        
    }
};