int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == goal){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    TC = O(N^2), SC = O(1)
------------------------------------------------------------------------------------
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt1 = func(nums, goal);
        int cnt2 = func(nums, goal - 1);
        return cnt1 - cnt2;
    }
    int func(vector<int>& nums, int x){
        if(x < 0) return 0;
        int l = 0;
        int cnt = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum > x){
                sum -= nums[l];
                l++;
            }
            cnt += i - l + 1;
        }
        return cnt;
    }
    TC =O(N), SC = O(1)