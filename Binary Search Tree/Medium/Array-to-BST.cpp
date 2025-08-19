//Given a sorted array. Convert it into a Height Balanced BST and return smallest lexiographical preorder

void preorder(vector<int>&nums, int start, int end, vector<int>& ans){
        if(start > end) return;
        int mid = start + ( end - start) / 2;
        ans.push_back(nums[mid]);
        preorder(nums, start, mid - 1, ans);
        preorder(nums, mid + 1, end, ans);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        preorder(nums, 0, nums.size() - 1, ans);
        return ans;
    }

//Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.
Node* func(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        Node* node = new Node(nums[mid]);
        node->left = func(nums, start, mid - 1);
        node->right = func(nums, mid + 1, end);
        return node;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        Node* temp = func(nums, 0, nums.size() - 1);
        return temp;
    }
    TC = O(N), SC = O(H)