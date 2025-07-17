/*
TC = O(LOFN), SC = O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            //reduce search space
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
            }
            //left side is sorted
            else if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid-1;
                }
                else {
                    low = mid + 1;
                }
            }
            //right side is sorted
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};
*/