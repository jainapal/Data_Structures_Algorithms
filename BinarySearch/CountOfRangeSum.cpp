/*
TC = O(N^2), SC = O(1)

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum <= upper && sum >= lower) cnt++;
            }
        }
        return cnt;
    }
};


----------------------------------Binary Search-------------------------------------------

TC = O(LOG N), SC = O(1)


*/