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
        if(head == NULL || head->next == NULL)return NULL;
        ListNode* f = head;
        for(int i = 0;i<n;i++) f = f->next;
        ListNode* s = head;
        if(f == NULL)return head->next;
        while(f!= NULL && f->next != NULL){
            f = f->next;
            s = s->next;
        }
        s->next = s->next->next;
        return head;
    }
};