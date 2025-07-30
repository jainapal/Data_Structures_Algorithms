class Solution {
public:
    vector<int> LLTraversal(ListNode *head) {
        vector<int> ans;
        ListNode *temp = head;
        while(temp != nullptr){
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
        return ans;

    }
};
TC = O(N)