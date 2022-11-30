//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        // k size is given and we have to revers this linked list in that size
        // we will be usin the stack for this purpose first we will be pushing the 
        // elements in the stack as they are now reversed so now we will update the node's value
        struct node* temp = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        // temp = head;
        int n = size/k;
        // this is no of segements of size k for each segement we need a stack and then do the 
        // reversing the process
        struct node* ptr = head;
        for(int i = 0;i<n;i++){
            stack<int>stk;
            temp = ptr;
            int t = 0;
            while(t != k){
                t++;
                stk.push(temp->data);
                temp = temp->next;
            }
            while(ptr != temp){
                ptr->data  = stk.top();
                stk.pop();
                ptr = ptr->next;
            }
            // now reversed the pointer
        }
        if(size %k != 0){
            stack<int>stk;
            temp = ptr;
            while(temp != NULL){
                stk.push(temp->data);
                temp = temp->next;
            }
            while(ptr != NULL && ptr != temp){
                ptr->data = stk.top();
                stk.pop();
                ptr = ptr->next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends