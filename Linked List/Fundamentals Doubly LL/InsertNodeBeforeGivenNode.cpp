void insertBeforeGivenNode(ListNode* node, int X) {

        ListNode* back = node -> prev;
        ListNode* newnode = new ListNode(X,node,back);
        back -> next = newnode;
        node -> prev = newnode;
    }
    TC = O(1), sc = O(1)