    void func(int last, int k, int sum,vector<int>& temp, vector<vector<int>>& ans){
        if(sum == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(sum <= 0 || temp.size() > k) return;
        for(int i = last ; i <= 9; i++){
            if(i <= sum){
                temp.push_back(i);
                func(i+1, k, sum-i, temp, ans);
                temp.pop_back(i);
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<int> temp;
        vector<vector<int>> ans;
        func(1,k,n,temp,ans);
        return ans;
    }