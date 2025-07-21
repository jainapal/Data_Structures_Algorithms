/*
 TC = O(N), SC = O(1)

 class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ i ;
            ans = ans ^ nums[i];
        }
        ans ^= n;
        return ans;
    }
};

 */