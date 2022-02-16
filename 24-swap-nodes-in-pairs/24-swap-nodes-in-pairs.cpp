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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* l = head;
        ListNode* r = l->next;
        head = r;
        r = r->next;
        head->next = l;
        l->next = r;
        while(l->next != NULL && l->next->next != NULL) {
            ListNode* prev = l;
            l = l->next;
            r = l->next;
            l->next = r->next;
            r->next = l;
            prev->next = r;
            
        }
        
        return head;
    }
};