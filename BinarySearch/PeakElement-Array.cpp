/*

TC = O(N), SC = O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(); 
        
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1]){
                return i;
            }
        }
        return -1 ;
    }
};

----------------------------------Optimised Approach---------------------------------
TC = O(LOGN), SC = O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1]? 0 : 1;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int left = (mid == 0) ? INT_MIN : nums[mid-1];
            int right = (mid == n-1) ? INT_MIN : nums[mid + 1];
            if(nums[mid] > left && nums[mid] > right){
                return mid;
            }
            else if(nums[mid] < right){
                low = mid + 1;
            }
            else if(nums[mid] < left){
                high = mid - 1;
            }
        }
        return -1;
    }
};

CAN BE WRITTEN IN ANOTHER WAY

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low < high){
            int mid = low + (high - low)/2;

            if(nums[mid] > nums[mid + 1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

*/