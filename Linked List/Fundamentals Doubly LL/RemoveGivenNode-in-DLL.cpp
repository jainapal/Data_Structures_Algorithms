void deleteGivenNode(ListNode* node) {
        ListNode* back = node -> prev;
        ListNode* front = node -> next;
        //if node is tail of dll
        if(front == NULL){
            back -> next = NULL;
        }
        else{
            front -> prev = back;
            back -> next = front;
            node -> next = nullptr;
            node -> prev = nullptr;
        }
        //TC = O(1), SC = O(1)
    }