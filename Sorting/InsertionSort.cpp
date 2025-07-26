    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            for(int j = i; j > 0 ;j--){
                if(nums[j] < nums[j - 1]){
                    swap(nums[j], nums[j-1]);
                }
                else break;
            }
        }
        return nums;
    }
    TC = O(N ^ 2), SC = O(1)