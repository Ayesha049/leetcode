/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*>v;
        ListNode * node = head;
        while(node != NULL) {
            v.push_back(node);
            node = node->next;
        }
        int last = v.size() - k;
        ListNode * prev1 = k-2 < 0 ? NULL : v[k-2];
        ListNode * prev2 = last-1 <0 ? NULL : v[last-1];
        prev1 != NULL ? prev1->next = v[last] : head = v[last];
        ListNode* lastNext = v[last]->next;
        v[last]->next = v[k-1]->next != v[last] ? v[k-1]->next : v[k-1];
        if(prev2 != v[k-1]) {
            prev2 != NULL ? prev2->next = v[k-1] : head = v[k-1];
        }
        v[k-1]->next = lastNext;
        return head;
        
    }
};