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
    ListNode* merge(ListNode* l, ListNode* r) {
        if(l == NULL) return r;
        if(r == NULL) return l;
        ListNode* head = NULL;
        if(l->val < r->val) {
            head = l;
            l=l->next;
        } else {
            head = r;
            r = r->next;
        }
        ListNode* node = head;
        while(l!=NULL && r!=NULL) {
            if(l->val < r->val) {
                node->next = l;
                l=l->next;
            } else {
                node->next = r;
                r = r->next;
            }
            node = node->next;
        }
        while(l!=NULL) {
            node->next = l;
            l=l->next;
            node = node->next;
        }
        while(r!=NULL) {
            node->next = r;
            r=r->next;
            node = node->next;
        }
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* node = head->next;
        while(node != NULL && node->next != NULL && node->next->next != NULL) {
            prev = prev->next;
            node = node->next->next;
        }
        ListNode* newHead = prev->next;
        prev->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(newHead);
        return merge(left,right);
    }
};