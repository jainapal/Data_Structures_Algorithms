class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if(head==NULL) return NULL;
        ListNode* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
};
TC = O(1)