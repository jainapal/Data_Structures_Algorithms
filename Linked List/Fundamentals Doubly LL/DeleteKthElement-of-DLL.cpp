ListNode* deleteKthElement(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            if(cnt == k) break;
            temp = temp -> next;
        }
        if(temp == NULL) return head;
        // if node to be deleteed is head of list
        else if(temp -> prev == NULL){
            head = temp -> next;
            temp -> next -> prev = NULL;
        }
        //if node is tail 
        else if( temp -> next == NULL) temp -> prev -> next = NULL;
        else {
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
        }
        delete temp;
        return head;
        
    }
    // TC = O(n) n is no. of elements in ll
    //SC = O(1)