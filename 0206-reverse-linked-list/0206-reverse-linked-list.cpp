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
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        // now we have to take the reamining list
        ListNode* rem = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return rem;
    }
    ListNode* reverseList(ListNode* head) {
        //we have to revest teh linked lis.
        return reverseLL(head);
    }
};