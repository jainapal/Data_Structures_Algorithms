class Solution {
public:
    ListNode* insertAtTail(ListNode* &head, int X) {
        ListNode* newNode=new ListNode(X);
        if(head==NULL) {
            return new ListNode(X);
        }
        ListNode* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
        return head;

    }
};
TC = O(N)