    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(ans.size() == 0 || ans[0] != nums[i]){
                int cnt = 0;
                for(int j = 0; j< n; j++){
                    if(nums[i] == nums[j]) cnt++;
                }
                if(cnt > n/3) ans.push_back(nums[i]);
            }
            if(ans.size() == 2) break;
        }
        return ans;
    }
    TC = O(N^2), SC = O(1)
---------------------------------------------------------------
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;
        for(auto& pair : mp){
            if(pair.second > n/3) ans.push_back(pair.first);
            if(ans.size() == 2) break;
        }

        return ans;
    }
    TC + O(NLOGN), SC = O(N)
--------------------------------------------------------------------
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int ele1, ele2;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2++;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }

        }

        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        int mini = n / 3 + 1;
        vector<int> ans;
        if(cnt1 >= mini) ans.push_back(ele1);
        if(cnt2 >= mini && ele1 != ele2) ans.push_back(ele2);

        return ans;
    }
    TC = O(N + N), SC = O(1)