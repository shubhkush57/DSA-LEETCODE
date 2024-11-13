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
    void reorderList(ListNode* head) {
        // we hvae to reorder the linked list hrere
        stack<ListNode*>stk;
        ListNode* temp = head;
        ListNode* tempAns = new ListNode(0);
        ListNode* ans = tempAns;
        int siz= 0;
        while(temp != NULL){
            ListNode* t = temp->next;
            // temp->next = NULL;
            stk.push(temp);
            temp = t;
            siz++;
        }
        int iterations = siz/2;
        cout<<iterations<<endl;
        ListNode* ptr1 = head;
        for(int i = 0;i<iterations;i++){

            ListNode* t = ptr1->next;
            ptr1->next = NULL;
            tempAns->next= ptr1;
            tempAns = tempAns->next;
            tempAns->next = stk.top();stk.pop();
            tempAns = tempAns->next;
            tempAns->next = NULL;
            ptr1 = t;

        }
        if(siz%2 == 1){
            tempAns->next = ptr1;
            tempAns= tempAns->next;
            tempAns->next = NULL;
        }
        head = ans->next;
        return ;
    }
};