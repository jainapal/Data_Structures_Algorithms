int maxScore(vector<int>& cardScore , int k){
        int n = cardScore.size();
        int leftsum = 0, rightsum = 0, maxsum = 0;
        for(int i = 0; i < k; i++){
            leftsum += cardScore[i];
            maxsum = leftsum;
        }
        int ind = n - 1;
        for(int i = k-1; i >= 0; i--){
            leftsum -= cardScore[i];
            rightsum += cardScore[ind];
            ind--;
            maxsum = max(maxsum , rightsum + leftsum);
        }
        return maxsum;
    }
    TC = O(K + K), SC = O(1)