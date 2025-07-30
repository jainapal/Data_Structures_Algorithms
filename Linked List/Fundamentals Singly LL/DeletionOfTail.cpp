class Solution {
public:
    ListNode* deleteTail(ListNode* &head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode* temp = head;
        while(temp -> next -> next != NULL) temp = temp -> next;
        delete temp->next;
        temp->next=NULL;
        return head;
    }
};
TC = O(N)