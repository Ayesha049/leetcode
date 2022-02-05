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

class myclass{
public:
    int val;
    ListNode* p;
    myclass(int v, ListNode* pp) {
        val = v;
        p = pp;
    }
};

class compare{
public:
    bool operator()(myclass &a, myclass &b){
        return a.val>b.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<myclass, vector<myclass>, compare> q;
        ListNode* node = NULL;
        ListNode* head = NULL;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) {
                q.push(myclass(lists[i]->val,lists[i]));
            }
        }
        while(!q.empty()) {
            ListNode * n = q.top().p;
            q.pop();
            if(head==NULL) {
                head = n;
                node = head;
            } else {
                node->next = n;
                node = node->next;
            }
            if(n->next!=NULL) {
                n=n->next;
                q.push(myclass(n->val,n));
            }
        }
        return head;
    }
};