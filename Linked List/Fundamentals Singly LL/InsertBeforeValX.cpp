class Solution {
public:
    ListNode* insertBeforeX(ListNode* &head, int X, int val) {
        if(head == NULL) return NULL;
        if(head->val == X) return new ListNode(val,head);
        ListNode *temp = head;
        while(temp->next != nullptr ){
            if(temp->next->val == X){
                ListNode* newNode = new ListNode(val,temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
TC = O(N)