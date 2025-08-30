/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode* deleteTail(ListNode* head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode* temp = head;
        while(temp -> next != NULL) temp = temp -> next;
        ListNode* newtail = temp->prev;
        newtail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return head;
    }
};
TC = O(N), SC = O(1)