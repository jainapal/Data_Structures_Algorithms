    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        int len = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum += nums[k];
                }
                if(sum == k) len = max(len, j - i + 1);
            }
        }
        return len;
    }
    TC = O(N ^ 3), SC = O(1)
-------------------------------------------------------------------------
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            int len = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k){
                    len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
    TC = O(N^2), SC = O(1)
-------------------------------------------------------------------------------
    int longestSubarray(vector<int> &nums, int k){
        map<int,int> prefixSum;
        int n = nums.size();
        int sum = 0, maxlen = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k){
                maxlen = max(maxlen, i+1);
            }
            int rem = sum - k;
            if(prefixSum.find(rem) != prefixSum.end()){
                int len = i - prefixSum[rem];
                maxlen = max(maxlen, len);
            }
            //we need longest so here if sum already not present then we add it into map
            //if it is already present and we update it then we get smallest subarr
            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
        return maxlen;
    }
    TC = O(N * LOGN) as we use ordered map, SC = O(N)