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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head = NULL;
        ListNode* node = head;
        int sum = 0;
        int cary = 0;
        while(l1!=NULL && l2!=NULL)
        {
            sum = l1->val+l2->val+cary;
            cary = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            if(head==NULL)
            {
                head = temp;
                node = head;
            }
            else
            {
                node->next = temp;
                node=node->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            sum = l1->val+cary;
            cary = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            node->next = temp;
            node=node->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            sum = l2->val+cary;
            cary = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            node->next = temp;
            node=node->next;
            l2=l2->next;
        }
        if(cary>0)
        {
            ListNode* temp = new ListNode(cary);
            node->next = temp;
            node=node->next;
        }
        return head;
    }
};