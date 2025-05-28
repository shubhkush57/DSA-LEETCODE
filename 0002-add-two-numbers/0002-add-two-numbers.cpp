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
 // we have to take carry forward..
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // make a new node each time and update it..
        ListNode* head = new ListNode(0);
        ListNode*temp = head;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val+l2->val+carry;
            carry  = sum/10;
            sum = sum%10;
            ListNode* newNode = new ListNode(sum);
            head->next = newNode;
            head = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
           int sum = l1->val+carry;
            carry  = sum/10;
            sum = sum%10;
            ListNode* newNode = new ListNode(sum);
            head->next = newNode;
            head = newNode;
            l1 = l1->next;
         
        }
        while(l2 != NULL){
           int sum = l2->val+carry;
            carry  = sum/10;
            sum = sum%10;
            ListNode* newNode = new ListNode(sum);
            head->next = newNode;
            head = newNode;
            l2 = l2->next;
         
        }
        if(carry != 0){
             ListNode* newNode = new ListNode(carry);
            head->next = newNode;
        }
        return temp->next;
    }
};