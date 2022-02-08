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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l = head;
        ListNode* r = head;
        for(int i=0;i<n;i++) {
            if(r == NULL) return head;
            r = r->next;
        }
        if(r == NULL) {
            return l->next;
        }
        while(r->next != NULL) {
            r = r->next;
            l = l->next;
        }
        if(l->next != NULL) {
            l->next = l->next->next;
        }
        return head;
    }
};