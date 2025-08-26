--> you can do sorting, TC = o(nlogn)
--> build min heap and delete k elements, TC = O(n + klogn)
---> most optimised method below
int kthSmallest(vector<int> &arr, int k) {
        
        //max heap
        priority_queue<int> pq;
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }

    TC = O(NLOGK), SC = O(1)