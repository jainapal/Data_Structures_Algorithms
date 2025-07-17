/*
TC = O(N), SC = O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
        }
        return mini;
    }
};

-----------------------------Optimised Approach------------------------------------------

TC = O(LOGN), SC = O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low)/ 2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};
*/