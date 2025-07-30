    vector<int> singleNumber(vector<int>& nums){
		int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;
        for(auto it : mp){
            if(it.second == 1) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
	}
    TC = O(N), SC = O(N)
----------------------------------------------------------------------------
    vector<int> singleNumber(vector<int>& nums){
			int n = nums.size();
            long xrr = 0;
            for(int num : nums) xrr ^= num;

            int rightSetbit = (xrr & (xrr-1)) ^  xrr;
            int xrr1 = 0, xrr2 = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] & rightSetbit) xrr1 = xrr1 ^ nums[i];
                else xrr2 = xrr2 ^ nums[i];
            }
            if(xrr1 < xrr2) return {xrr1, xrr2};
            return {xrr2, xrr1};
            
		}
        TC = O(N), SC = O(1)