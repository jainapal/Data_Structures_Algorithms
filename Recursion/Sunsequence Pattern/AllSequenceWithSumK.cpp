int func(int ind, int sum, vector<int> nums){
        if(sum==0) return 1;
        if(sum < 0 || ind == nums.size()) return 0;
        return func(ind + 1, sum - nums[ind], nums) + func(ind +1, sum, nums);
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
        return func(0, k, nums);
    }

//how would you modify this to return subsequences

void func(int ind, int sum, vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int k) {
    if (ind == nums.size()) {
        if (sum == 0) {
            result.push_back(path);
        }
        return;
    }

    // Include current element
    path.push_back(nums[ind]);
    func(ind + 1, sum - nums[ind], nums, path, result, k);
    path.pop_back();

    // Exclude current element
    func(ind + 1, sum, nums, path, result, k);
}

vector<vector<int>> allSubsetsWithTargetSum(vector<int>& nums, int k) {
    vector<vector<int>> result;
    vector<int> path;
    func(0, k, nums, path, result, k);
    return result;
}

//can this be extended to multi dimensional array

void dfs(int i, int j, int sum, vector<vector<int>>& matrix, vector<int>& path, vector<vector<int>>& result, int k) {
    int n = matrix.size(), m = matrix[0].size();
    if (i >= n || j >= m) return;

    sum += matrix[i][j];
    path.push_back(matrix[i][j]);

    if (i == n-1 && j == m-1) {
        if (sum == k) result.push_back(path);
        path.pop_back();
        return;
    }

    dfs(i + 1, j, sum, matrix, path, result, k); // down
    dfs(i, j + 1, sum, matrix, path, result, k); // right

    path.pop_back();
}

vector<vector<int>> allPathsWithTargetSum(vector<vector<int>>& matrix, int k) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(0, 0, 0, matrix, path, result, k);
    return result;
}