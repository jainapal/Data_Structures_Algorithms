//contains duplicates
    void func(int ind,int sum,vector<int>& arr,vector<int>& temp, vector<vector<int>>& ans){
        if(sum == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[ i - 1]) continue; //skip duplicate
            if(arr[i] > sum ) break;  //optimisation
            temp.push_back(arr[i]);
            func(i + 1, sum - arr[i], arr, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        func(0,target,candidates,temp,ans);
        return ans;
    }