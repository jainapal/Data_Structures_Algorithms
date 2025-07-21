void func(int ind, int sum, vector<vector<int>>& arr, vector<int>& temp, vector<vector<int>>& ans){
    if(sum == 0){
        ans.push_back(temp);
        return;
    }
    if(sum < 0 || ind == arr.size()) return;

    temp.push_back(arr[ind]);
    func(ind, sum - arr[ind], arr, temp, ans);
    temp.pop_back(arr[ind]);
    func(ind + 1, sum , arr, temp, ans);
}

vector<vector<int>> combinationSum(vector<int> candidate, int target){

    vector<vector<int>> ans;
    vector<int> temp;
    func(0, target, candidate, temp, ans)
    return ans;
}

//What if candidates can only be used once???
temp.push_back(arr[ind]);
func(ind + 1, sum - arr[ind], arr, temp, ans);
temp.pop_back(arr[ind]);
func(ind + 1, sum , arr, temp, ans);
