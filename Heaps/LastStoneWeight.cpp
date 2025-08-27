int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(int i = 0; i < stones.size(); i++){
            p.push(stones[i]);
        }
        while(p.size() > 1){
            int weight = p.top();
            p.pop();
            weight -= p.top();
            p.pop();
            if(weight) p.push(weight);
        }
        //if p is empty return 0
        return p.empty() ? 0 : p.top();
    }
    TC = O(NLOGN), SC = O(1)