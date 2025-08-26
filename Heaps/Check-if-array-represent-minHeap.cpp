bool isHeap(vector<int>& nums) {
        int n = nums.size();
        //iterating non leaf nodes
        for(int i = n/2 - 1; i >=0; i--){
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n && nums[left] < nums[i]) return false;
            if(right < n && nums[right] < nums[i]) return false;
        }
        return true;
    }
    TC = O(N), SC = O(1)