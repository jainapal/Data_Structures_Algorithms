vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> ans;
        for(int i = 0; i <= n - k; i++){
            int maxi = arr[i];
            for(int j = i; j < i + k; j++){
                maxi = max(maxi, arr[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
    TC = O(N-K * K), SC = O(N - K);
--------------------------------------------------------------------------------------
vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i < n; i++){ 
            //update dq to maintain curr window;
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            //maintain monotonic decreasing order of element
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            //add curr element index to deque
            dq.push_back(i);
            //store max element from first window
            if(i >= (k - 1)){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
    TC = O(N) + O(N), SC = O(K) + O(N - K)