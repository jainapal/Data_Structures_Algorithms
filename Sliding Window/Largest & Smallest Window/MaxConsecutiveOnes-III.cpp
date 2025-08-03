int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            int zero = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0) zero++;
                if(zero <= k){
                    int len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
                else break;
            }
        }
        return maxlen;
        
    }
    TC = O(N^2), SC = O(1)
----------------------------------------------------------------------------
int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0, zero = 0;
        int l = 0, r = 0;

        while( r < n){
            if(nums[r] == 0) zero++;
            while(zero > k){
                if(nums[l] == 0) zero--;
                l++;
            }
            int len = r - l + 1;
            maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
        
    }
    TC = O(2N), SC = O(1)
--------------------------------------------------------------------------
int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0, zero = 0;
        int l = 0, r = 0;

        while( r < n){
            if(nums[r] == 0) zero++;
            if(zero > k){
                if(nums[l] == 0) zero--;
                l++;
            }
            if(zero <= k){
                int len = r - l +1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen; 
    }
    TC = O(N), SC = O(1)