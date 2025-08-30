ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newnode = new ListNode(X, head, nullptr);
        if(head != nullptr){
            head -> prev = newnode;
        }
        return newnode;
        
    }
    TC = O(1), SC = O(1)