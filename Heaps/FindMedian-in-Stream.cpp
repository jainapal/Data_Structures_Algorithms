vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxp; //left max heap
        priority_queue<int, vector<int>, greater<int>> minp; //right min heap
        vector<double> ans;
        
        for(int x : arr){
            // push to correct heap
            if(maxp.empty() || x < maxp.top()) maxp.push(x);
            else minp.push(x);
            
            //Balance heap
            if(maxp.size() > minp.size() + 1){
                minp.push(maxp.top());
                maxp.pop();
            }
            else if(minp.size() > maxp.size()){
                maxp.push(minp.top());
                minp.pop();
            }
            
            //Find median
            if(minp.size() == maxp.size()){
                ans.push_back((maxp.top() + minp.top()) / 2.0);
            }
            else{
                //maxp will always have 1 more element in case of odd
                ans.push_back(maxp.top());
            }
        }
        
        return ans;
    }
    TC = O(nLOG(n)), SC = O(n)