bool isPrime(int n){
            if(n <= 1) return false;
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
            return true;
        }
        vector<int> primesInRange(vector<vector<int>>& queries){
            vector<int> ans;
            for(auto& it : queries){
                int l = it[0];
                int r = it[1];
                int cnt = 0;
                for(int j = l ; j <= r; j++){
                    if(isPrime(j)) cnt++;
                }
                ans.push_back(cnt);
            }
            return ans;
        }
        TC = O(Q * (R - L + 1) * sqrt(R))
        SC = O(1)
------------------------------------------------------------------------------------
