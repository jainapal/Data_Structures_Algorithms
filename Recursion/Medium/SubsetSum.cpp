void func(int ind, int sum , vector<int>& arr, vector<int>& ans){
    if(ind == arr.size()){
        ans.push_back(sum);
        return;
    }
    temp.push_back(arr[ind]);
    func(ind + 1,arr, temp, ans);
    temp.pop_back();
    func(ind + 1, arr, temp, ans);
}
vector<int> subsetSum(vector<int>& nums){
    vector<int> ans;
    func(0,0, nums, ans);
    return ans;
}

//"What if subsets must be generated explicitly?"
//Instead of just the sum, you need to explicitly store the elements of the subset.

void func(int ind, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
    if(ind == arr.size()){
        ans.push_back(temp);
        return;
    }
    func(ind + 1, sum + arr[ind], arr, ans);
    func(ind + 1, sum, arr, ans);
}
vector<int> subsetSum(vector<int>& nums){
    vector<int> temp;
    vector<vector<int>> ans;
    func(0,nums, temp, ans);
    return ans;
}
