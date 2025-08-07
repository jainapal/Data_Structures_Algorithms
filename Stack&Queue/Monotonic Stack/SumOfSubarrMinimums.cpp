int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int mini = arr[i];
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        return sum;
    }
    TC =O(N^2), SC =O(1)
------------------------------------------------------------------------------------
vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n -1; i >= 0; i--){
            int curr = arr[i];
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int> &arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;

        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left * right *1LL;
            int val = (freq * arr[i]) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
    TC = O(2N + N), SC =O(N + N)