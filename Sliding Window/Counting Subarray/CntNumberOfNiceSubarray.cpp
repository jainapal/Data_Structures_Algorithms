int numberOfOddSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(nums[j] % 2 != 0){
                    cnt++;
                }
                if(cnt == k) ans++;
            }
        }
        return ans;
    }
    TC = O(N^2), SC = O(1)
----------------------------------------------------------------------------------------
int numberOfOddSubarrays(vector<int>& nums, int k) {
        int cnt1 = func(nums, k);
        int cnt2 = func(nums, k - 1);
        return cnt1 - cnt2;
    }
    int func(vector<int>& nums, int k){
        int l = 0, r = 0;
        int ans = 0, cnt = 0;
        while(r < nums.size()){
            if(nums[r] % 2 != 0){
                cnt++;
            }
            while(cnt > k){
                //only odd cnt decreases
                cnt -= nums[i] % 2;
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
    TC = O(2N), SC =O(1)