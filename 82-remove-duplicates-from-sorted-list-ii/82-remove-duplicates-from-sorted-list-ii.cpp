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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* l = head;
        ListNode* r = head->next;
        int cnt = 1;
        while(r != NULL) {
            if(l->val == r->val) {
                cnt++;
            } else {
                if(cnt>1) {
                    if(prev == NULL) {
                        head = r;
                        l = r;
                    } else {
                        prev->next = r;
                        l = r;
                    }
                    cnt = 1;
                } else {
                    prev = l;
                    l = l->next;
                }
            }
            r = r->next;
        }
        if(cnt>1) {
            if(prev == NULL) {
                head = r;
            } else {
                prev->next = r;
            }
        }
        return head;
    }
};