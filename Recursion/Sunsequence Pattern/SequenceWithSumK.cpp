    bool func(int ind, int sum, vector<int>& nums){
        if(sum==0) return true;
        if(sum < 0 || ind==nums.size()) return false;
        return func(ind +1, sum - nums[ind], nums) || func(ind +1, sum, nums);
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {

        return func(0,k,nums);
    }

    // How would you modify this to return subsequence

    bool func(int ind, int sum, vector<int>& nums, vector<int>& path, vector<int>& result) {
    if (sum == 0) {
        result = path;  // Store this valid subsequence
        return true;
    }
    if (ind == nums.size() || sum < 0) return false;

    // Include the current element
    path.push_back(nums[ind]);
    if (func(ind + 1, sum - nums[ind], nums, path, result)) return true;
    path.pop_back();  // Backtrack

    // Exclude the current element
    if (func(ind + 1, sum, nums, path, result)) return true;

    return false;
}

vector<int> getSubsequenceWithSumK(vector<int>& nums, int k) {
    vector<int> path;
    vector<int> result;
    func(0, k, nums, path, result);
    return result;
}

//how would you handle approximate sum eg, |sum - k| <= tolerance

bool func(int ind, int sum, vector<int>& nums, vector<int>& path, vector<int>& result, int k, int tolerance) {
    if (abs(sum - k) <= tolerance) {
        result = path;  // Found a valid subsequence within tolerance
        return true;
    }
    if (ind == nums.size()) return false;

    // Include current element
    path.push_back(nums[ind]);
    if (func(ind + 1, sum + nums[ind], nums, path, result, k, tolerance)) return true;
    path.pop_back();

    // Exclude current element
    if (func(ind + 1, sum, nums, path, result, k, tolerance)) return true;

    return false;
}

vector<int> getApproxSubsequenceWithSumK(vector<int>& nums, int k, int tolerance) {
    vector<int> path, result;
    func(0, 0, nums, path, result, k, tolerance);
    return result;
}
 
