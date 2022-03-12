/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        Node* node = head;
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        node = node->next;
        Node* node2 = newHead;
        while(node!=NULL) {
            Node* temp = new Node(node->val);
            mp[node] = temp;
            node = node->next;
            node2->next = temp;
            node2 = node2->next;
        }
        node2->next = NULL;
        node = head;
        node2 = newHead;
        while(node!=NULL) {
            if(node->random != NULL) {
                node2->random = mp[node->random];
            }
            node = node->next;
            node2 = node2->next;
        }
        return newHead;
    }
};