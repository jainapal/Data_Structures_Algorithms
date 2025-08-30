ListNode* insertBeforeTail(ListNode* head, int X) {
        if(head == nullptr || head -> next == nullptr){
            ListNode* node = new ListNode(X, head, nullptr);
            head -> prev = node;
            return node;
        }

        ListNode* node = new ListNode(X);
        ListNode* temp = head;
        while(temp -> next != nullptr) temp = temp -> next;
        temp -> prev -> next = node;
        node -> prev = temp -> prev;
        node -> next = temp;
        temp -> prev = node;
        return head;
    }
    TC =O(N), SC = O(1)