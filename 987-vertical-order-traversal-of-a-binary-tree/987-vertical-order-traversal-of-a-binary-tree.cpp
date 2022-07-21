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
    void func(TreeNode* node, int hd, int vd, map<int,vector<pair<int,int> > >&mp) {
        if(node == NULL) return;
        mp[hd].push_back(make_pair(vd,node->val));
        func(node->left, hd-1, vd+1, mp);
        func(node->right, hd+1, vd+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int> > >mp;
        vector<vector<int>> ans;
        func(root, 0, 0, mp);
        map<int,vector<pair<int,int> > > :: iterator it;
        for(it = mp.begin(); it!= mp.end(); it++) {
            vector<pair<int,int> > v = it->second;
            sort(v.begin(),v.end());
            vector<int>temp;
            for(int i=0;i<v.size();i++)
            {
                temp.push_back(v[i].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};