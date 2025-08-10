vector <int> stockSpan(vector<int> arr, int n) {
       vector<int> ans(n);
       for(int i = 0; i < n; i++){
        int curr = 0;
        for(int j = i; j >= 0; j--){
            if(arr[j] <= arr[i]) curr++;
            else break;
        }
        ans[i] = curr;
       }
       return ans;
    }
    TC = O(N^2), SC = O(1)
-------------------------------------------------------------------------------------
vector<int> findPGE(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector <int> stockSpan(vector<int> arr, int n) {
       vector<int> pge = findPGE(arr);
       vector<int> ans(n);
       for(int i = 0; i < n; i++){
        ans[i] = i - pge[i];
       }
       return ans;
    }
    TC = O(N + N), SC = O(N)