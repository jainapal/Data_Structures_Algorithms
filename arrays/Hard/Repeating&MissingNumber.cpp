    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int r = -1, m = -1;
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 0; j <n; j++){
                if(nums[j] == i){
                    cnt++;
                }
            }
            if(cnt == 0) m = i;
            if(cnt == 2) r = i;
            if(r != -1 && m != -1) break;
        }
        return {r, m};
    }
    TC = O(N^2), SC = O(1)
-----------------------------------------------------------------------------
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int r = -1, m = -1;
        int hash[n+1] = {0};
        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(hash[i] == 0) m = i;
            if(hash[i] == 2) r = i;
            if(r != -1 && m != -1) break;
        }
        return {r, m};
    }
    TC = O(N + N), SC = O(N)
------------------------------------------------------------------------------
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        long long sum1 = 0, sqsum1 = 0;
        for(int i = 0; i < n; i++){
            sum1 += nums[i];
            sqsum1 += nums[i] * nums[i];
        }
        long long sum2 = n *(n + 1) / 2;
        long long sqsum2 = n *(n + 1)*(2 * n + 1) / 6;
        
        long long val1 = sum1 - sum2; // x - y
        long long val2 = sqsum1 - sqsum2; // x**2 - y**2
        val2 = val2 / val1; // x + y
        long long x = (val1 + val2 ) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
    TC = O(N), SC = O(1)