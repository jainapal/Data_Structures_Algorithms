    void func(int ind, vector<int>& temp, vector<int>& arr, vector<vector<int>>& ans){
        if(ind == arr.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]) continue; //skip duplicate
            temp.push_back(arr[i]);
            func(ind + 1, temp,arr, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        func(0,temp,nums,ans);
        return ans;
    }

// can you solve this without sorting??
//Sorting simplifies the process of skipping duplicates, but you can use a 
//hash set to track generated subsets and ensure uniqueness without sorting.


    set<vector<int>> subset;
    void func(int ind, vector<int>& temp, vector<int>& arr){
        if(ind == arr.size()){
            vector<int> sortedTemp = temp;
            sort(sortedTemp.begin(), sortedTemp.end());
            subset.insert(sortedTemp);
            return;
        }
        temp.push_back(arr[ind]);
        func(ind+1, temp, ans);
        temp.pop_back();
        func(ind+1,temp,arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        subset.clear();
        vector<int> temp;
        func(0,temp,nums);
        return ans;
    }
