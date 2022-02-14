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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode * node = head->next;
        ListNode * prev = head;
        head->next = NULL;
        while(node->next!=NULL)
        {
            ListNode * temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        node->next = prev;
        return node;
    }
};