int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 1;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int cnt = 1;
            while(linearsearch(nums, x + 1)){
                x = x + 1;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
    bool linearsearch(vector<int>& nums, int num){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num) return true;
        }
        return false;
    }
    TC = O(N^2), SC = O(1)
---------------------------------------------------------------------
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int lastsmaller = INT_MIN;
        int cnt = 0, ans = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] - 1 == lastsmaller){
                cnt++;
                lastsmaller = nums[i];
            }
            else if(nums[i] != lastsmaller){
                cnt = 1;
                lastsmaller = nums[i];
            }
            ans = max(ans, cnt);
        }
        return ans;

    }
    TC = O(NLOGN + N), SC = O(1)
-----------------------------------------------------------------
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if( n == 0) return 0;
        int ans = 1;
        unordered_set<int> st;
        for(int num : nums) st.insert(num);

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x + 1) != st.end()){
                    x = x + 1;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
    TC = O(3 * N), SC = O(N)