vector<vector<int> > powerSet(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int subset = 1 << n; //total no. of subsets 
        for(int num = 0; num < subset; num++){
            vector<int> temp;
            //traverse on bit
            for(int i = 0; i < n; i++){
                //check if jth bit is set 
                if(num & (1 << i)) temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    TC = O(2^N * N), SC = O(2^N * N)