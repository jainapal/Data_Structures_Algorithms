    int singleNumber(vector<int>& nums) {        
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;
        for(auto it : mp){
            if(it.second == 1) return it.first;
        }
        return -1;
    }
    TC = O(N), SC = O(N)
--------------------------------------------------------------------------
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;        
        for(int i = 0; i <= 31; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] & (1 << i)) cnt++;
            }
            if(cnt % 3 != 0) ans |= (1 << i);
        }
        return ans;
    }
    TC = O(32 * N), SC = O(1)
-------------------------------------------------------------
    int singleNumber(vector<int>& nums) {        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[n-1];
        for(int i = 1; i < n; i += 3){
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return ans;
    }
    TC = O(NLOGN), SC = O(1)
--------------------------------------------------------------------------------

    int singleNumber(vector<int>& nums) {        
        int n = nums.size();
        int ones = 0, twos = 0;
        for(int i = 0; i < n; i++){
            //add in ones if not in twos
            ones = (ones ^ nums[i]) & ~twos;
            //add in twos if already in ones
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
    TC = O(N), SC = O(1)