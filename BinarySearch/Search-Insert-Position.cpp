/*
TC = O(N), SC = O(1)

class Solution {
    public:
    int searchInsert(vector<int> &nums, int target)  {
       for(int i = 0;i < nums.size(); i++){
          if(nums[i] >= target) return i;
        }
        return nums.size();
    }
};

----------------------------Optimal----------------------------------------------
TC = O(N), SC = O(1)

class Solution {
public:
    int searchInsert(vector<int> &nums, int target)  {
       int low = 0, high = nums.size() - 1, ans = nums.size();

       while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
       }
       return ans;
    }
};


*/