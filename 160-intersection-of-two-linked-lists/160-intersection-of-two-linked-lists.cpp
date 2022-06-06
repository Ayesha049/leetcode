/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool>seen;
        ListNode* node = headA;
        while(node!=NULL)
        {
            seen[node] = 1;
            node = node->next;
        }
        node = headB;
        while(node!=NULL)
        {
            if(seen.find(node)!=seen.end()) return node;
            node =  node->next;
        }
        return NULL;
    }
};