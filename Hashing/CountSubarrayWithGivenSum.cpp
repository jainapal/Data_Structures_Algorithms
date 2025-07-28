    int subarraySum(vector<int> &nums, int k){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int l=i;l<=j;k++){
                    sum+= nums[l];
                    if(sum==k) cnt++;
                }
            }
        }
        return cnt;
    }
    TC = O(N^3), SC = O(1)
-------------------------------------------------------------------------
    int subarraySum(vector<int> &nums, int k){
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                    sum += nums[j];
                    if(sum == k) cnt++;
            }
        }
        return cnt;
    }
    TC = O(N^2), SC = O(1)
---------------------------------------------------------------------------------
    int subarraySum(vector<int> &nums, int k){
        int n = nums.size();
        map<int, int> prefixSum;
        int cnt = 0;
        int sum = 0;
        prefixSum[0] = 1;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            int req = sum - k;
            cnt += prefixSum[req];
            prefixSum[sum]++;
        }
        return cnt;
    }
    TC = O(N * LOGN) AS I USE ORDERED MAP , SC = O(N)