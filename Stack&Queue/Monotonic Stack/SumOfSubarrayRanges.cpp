long long subArrayRanges(vector<int> &nums) {
      int n = nums.size();
      long long sum = 0;
      for(int i = 0; i < n; i++){
        int smallest = nums[i];
        int largest = nums[i];
        for(int j = i; j < n; j++){
            smallest = min(smallest, nums[j]);
            largest = max(largest, nums[j]);
            sum += (largest - smallest);
        }
      }
      return sum;
    }
    TC = O(N^2), SC =O(1)
--------------------------------------------------------------------------------
private:
    vector<int> findNSE(vector<int>& nums){
      int n = nums.size();
      vector<int> ans(n);
      stack<int> st;
      for(int i = n - 1; i >= 0; i--){
        int curr = nums[i];
        while(!st.empty() && nums[st.top()] >= curr){
          st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
      }
      return ans;
    }
    vector<int> findNGE(vector<int>& nums){
      int n = nums.size();
      vector<int> ans(n);
      stack<int> st;
      for(int i = n - 1; i >= 0; i--){
        int curr = nums[i];
        while(!st.empty() && nums[st.top()] <= curr){
          st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
      }
      return ans;
    }
    vector<int> findPSE(vector<int>& nums){
      int n = nums.size();
      vector<int> ans(n);
      stack<int> st;

      for(int i = 0; i < n; i++){
        int curr = nums[i];
        while(!st.empty() && nums[st.top()] > curr){
          st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      return ans;
    }
    vector<int> findPGE(vector<int>& nums){
      int n = nums.size();
      vector<int> ans(n);
      stack<int> st;
      for(int i = 0; i < n;i++){
        int curr = nums[i];
        while(!st.empty() && nums[st.top()] < curr){
          st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      return ans;
    }
    long long sumSubarrayMins(vector<int>& nums){
      int n = nums.size();
      long long sum = 0;
      vector<int> nse = findNSE(nums);
      vector<int> pse = findPSE(nums);

      for(int i = 0; i < n; i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        long long freq = left * right * 1LL;
        long long val = freq * nums[i] * 1LL;
        sum += val;
      }
      return sum;
    }
    long long sumSubarrayMaxs(vector<int>& nums){
      int n = nums.size();
      vector<int> nge = findNGE(nums);
      vector<int> pge = findPGE(nums);
      long long sum = 0;

      for(int i = 0; i < n; i++){
        int left = i - pge[i];
        int right = nge[i] - i;
        long long freq = left * right * 1LL;
        long long val = (freq * nums[i] * 1LL);
        sum += val;
      }
      return sum;
    }
public:
    long long subArrayRanges(vector<int> &nums) {
      return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
    }
};
TC = O(10N), SC = O(10N)