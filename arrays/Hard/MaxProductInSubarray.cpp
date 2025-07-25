    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n;i++){
            for(int j = i; j < n; j++){
                int prod = 1;
                for(int k = i; k <= j; k++){
                    prod *= nums[k];
                }
                ans = max(ans, prod);
            }
        }
        return ans;
    }
    TC = O(N^3), SC = O(1)
--------------------------------------------------------------
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n;i++){
            int prod = 1;
            for(int j = i; j < n; j++){
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }
        return ans;
    }
    TC = O(N^2), SC = O(1)
------------------------------------------------------------------
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int prefix = 1, suffix = 1;
        for(int i = 0; i < n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
    TC = O(N), SC = O(1)