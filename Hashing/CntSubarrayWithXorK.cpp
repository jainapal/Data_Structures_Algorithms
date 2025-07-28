    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int xrr = 0;
                for(int l = i; l <= j; l++){
                    xrr ^= nums[l];
                }
                if(xrr == k) cnt++;
            }
        }
        return cnt;
    }
    TC = O(N^3), SC = O(1)
--------------------------------------------------------------------------------
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int xrr = 0;
            for(int j = i; j < n; j++){
                xrr ^= nums[j];
                if(xrr == k) cnt++;
            }
        }
        return cnt;
    }
    TC = O(N^2), SC = O(1)
---------------------------------------------------------------------------------------
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int cnt = 0, xrr = 0;
        map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            xrr ^= nums[i];
            int req = k ^ xrr;
            cnt += mp[req];
            mp[xrr]++;
        }
        return cnt;
    }
    TC = O(N * LOGN), SC = O(N)