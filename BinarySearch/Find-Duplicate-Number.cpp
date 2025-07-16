/* TC = O(NLOGN), SC = O(1)

We define a check condition:

For a number mid, count how many numbers in the array are ≤ mid

If the count is more than mid, the duplicate is in the left half

Else, it’s in the right half

This works because:

Normally in [1...mid], we should have at most mid numbers

If we get more than mid, some number is repeated in that range

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int num : nums){
                if(num <= mid) cnt++;
            }
            if(cnt <= mid){
                left = mid + 1; //duplicate is on right sise
            }
            else{
                ans = mid; //potential duplicate
                right = mid - 1; //search in left part
            }

        }
        return ans;
    }
};


------------------------------Floyd’s Cycle Detection-----------------------------------


TC = O(N), SC = O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        //we use do while as at start slow = fast and if we 
        //not use it our while does not execute so to move it 
        //for once we use do while
        do{
            slow = nums[slow]; //1 step
            fast = nums[nums[fast]]; //2 steps
        }
        while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};




*/