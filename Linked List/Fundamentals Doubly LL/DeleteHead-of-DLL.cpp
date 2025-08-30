ListNode * deleteHead(ListNode* head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode *temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        return head;
    }
    TC = O(1), SC = O(1)