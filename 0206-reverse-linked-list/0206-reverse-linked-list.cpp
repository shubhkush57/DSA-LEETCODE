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
    ListNode* reverseList(ListNode* head) {
        ListNode* p2 = nullptr;
        ListNode* temp = head;
        while(temp != nullptr){
            ListNode* t = temp->next;
            temp->next = p2;
            p2 = temp;
            temp  =t ;
        }
        return p2;

    }
};