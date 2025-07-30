class Solution {
public:
    ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* newnode=new ListNode(X);
        newnode->next=head;
        head=newnode;
        return head;
    }
};
TC = O(1)