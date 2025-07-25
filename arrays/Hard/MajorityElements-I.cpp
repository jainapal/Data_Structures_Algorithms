    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt > n/2) {
                return nums[i];
            }
        }
        return -1;
    }
    TC = O(N^2), SC = O(1)
------------------------------------------------------------------
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        for(auto& pair : mp){
            if(pair.second > n/2) return pair.first;
        }
        return -1;
    }
    
    TC = O(N), SC = O(N)

------------------------------------------------------------  
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ele;
        for(int i = 1; i < n; i++){
            if(cnt == 0){
                cnt++;
                ele = nums[i];
            }
            else if(nums[i] == ele) cnt++;
            else cnt--;

        }
        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele) cnt1++;
        }
        if(cnt1 > n/2) return ele;
        return -1;
    }
    TC = O(N + N), SC = O(1)