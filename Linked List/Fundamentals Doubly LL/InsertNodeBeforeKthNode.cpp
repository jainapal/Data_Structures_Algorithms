ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {
        if(head == NULL) return NULL;
        if(K == 1){
            ListNode* newnode = new ListNode(X, head, nullptr);
            head -> prev = newnode;
            return newnode;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr){
            cnt ++;
            if(cnt == K){
                ListNode* back = temp -> prev;
                ListNode* newnode = new ListNode(X, temp, back);
                back -> next = newnode;
                temp -> prev = newnode;
                return head;
            }
            temp = temp -> next;
        }
        return nullptr;
    }
    TC = O(K), SC = O(1)