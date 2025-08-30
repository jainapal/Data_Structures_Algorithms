ListNode* arrayToLinkedList(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        ListNode* head = new ListNode(nums[0]);
        ListNode* prev = head;

        for(int i =1; i < nums.size(); i++){
            ListNode* temp = new ListNode(nums[i], nullptr, prev);
            prev -> next = temp;
            prev = temp;
        }
        return head;
    }
    TC = O(N), SC = O(N)