

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*>q;
        q.push(root);
        root->next = NULL;
        while(!q.empty())
        {
            int sz = q.size();
            Node * node=NULL;
            for(int i=0;i<sz;i++)
            {
                node = q.front();
                q.pop();
                node->next = i<sz-1 ? q.front() : NULL;
                Node* L = node->left;
                Node* R = node->right;
                if(L!=NULL)
                {
                    q.push(L);
                }
                if(R!=NULL)
                {
                    q.push(R);
                }
            }
            
        }
        return root;
    }
};