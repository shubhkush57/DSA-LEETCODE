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

        ListNode* remLL = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return remLL;
    }
    void reorderList(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* ptr2 = reverseLL(slow->next);
        slow->next = NULL;
        ListNode* ptr1 = head;
        while(ptr1 != NULL){
            temp->next = ptr1;
            ptr1 = ptr1->next;
            temp = temp->next;
            temp->next = NULL;
            if(ptr2 != NULL){
                temp->next = ptr2;
                ptr2 = ptr2->next;
                temp = temp->next;
                temp->next = NULL;
            }

        }

        head = ans->next ;
        return;
    }
};