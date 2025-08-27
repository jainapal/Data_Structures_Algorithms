int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> p;
        
        for(int i = 0; i < arr.size(); i++){
            p.push(arr[i]);
        }
        int cost = 0;
        while(p.size() > 1){
            int rope = p.top(); //first rope
            p.pop();
            rope += p.top(); //second rope
            p.pop();
            cost += rope; //cost to merge two ropes
            p.push(rope);
        }
        return cost;
    }
    TC = O(NLOGN), SC = O(1)