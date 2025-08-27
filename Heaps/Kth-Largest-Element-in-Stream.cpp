vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        
        for(int i= 0; i < k; i++){
            pq.push(arr[i]);
            if(pq.size() != k) ans.push_back(-1);
            else ans.push_back(pq.top());
        }
        
        for(int i = k; i < n; i++){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
    TC = O(NLOG(K)), SC = O(N)