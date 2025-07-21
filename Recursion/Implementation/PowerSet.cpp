vector<vector<int> > powerSet(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int> ans;

    func(0,nums.size(),nums, temp, ans);
    return ans;
}

void func(int ind, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
    if(ind == n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[ind]);
    func(ind + 1, n, nums, temp, ans);
    temp.pop_back();
    func(ind + 1, n, nums, temp, ans);
}

//How would you modify this to generate subset of fixed size k
//just a small change in base case

if(temp.size() == k) push it to ans and return
if(ind == n) return

// What if duplicates are allowed in input array
// sort the array and skip duplicates

for (int i = ind; i < n; ++i) {
        // Skip duplicates
        if (i > ind && nums[i] == nums[i - 1]) continue;

        temp.push_back(nums[i]);
        func(i + 1, n, nums, temp, ans, k);
        temp.pop_back();
    }