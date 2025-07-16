/* TC = O(LOG N)

int upperBound(vector<int> &nums, int x){
    int len = nums.size();
    int low = 0, high = len - 1, ans = len;

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] <= x){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
*/