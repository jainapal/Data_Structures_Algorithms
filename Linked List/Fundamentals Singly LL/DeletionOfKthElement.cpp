class Solution {
public:
    ListNode* deleteKthNode(ListNode* &head, int k) {
        if(head==NULL) return NULL;
        if(k==1){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode* temp=head;
        for(int i = 0; i < k - 2; i++){
            temp = temp -> next;
        }
        if(temp == NULL || temp -> next == NULL) return head;

        ListNode *next = temp -> next -> next;
        delete temp -> next;
        temp -> next = next;
        return head;
        
    }
};
TC = O(N)