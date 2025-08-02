int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                left[i] = left[i - 1] + 1;
            }
            else left[i] = 1;
        }
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i + 1] + 1;
            }
            else right[i] = 1;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += max(left[i], right[i]);
        }
        return sum;
    }
    TC = O(3N), SC = O(2N)
------------------------------------------------------------------------

int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0) return 0;
        
        vector<int> candies(n,1);
        int ans = 0;
        //left to rght 
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        //right to left
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            ans += candies[i];
        }
        

        return ans + candies[n-1];
    }
    TC = O(2N), SC = O(N)
-------------------------------------------------------------------------------
int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int total = 1; //one candy for first child
        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                total = total + 1;
                i++;
                continue; // move to next iteration
            }
            int peak = 1; //candy cnt for increasing rating trend
            while(i < n && ratings[i] > ratings[i - 1]){
                peak++; //increment candy cnt for incresing trend
                total += peak;
                i++;
            }
            int down = 1; // candy cnt for dec rating trend
            while(i < n && ratings[i] < ratings[ i - 1]){
                total += down;
                down++;
                i++;
            }
            if( down > peak){
                total += down - peak;
            }
        }
        return total;
    }
    TC = O(N), SC = O(1)