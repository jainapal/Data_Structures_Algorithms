int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int hash[3] = {0};
            for(int j = i; j < n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    cnt++;
                }

            }
        }
        return cnt;
    }
    TC = O(N ^ 2), SC = O(3)
---------------------------------------------------------------------------
int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int lastSeen[3] = {-1, -1, -1};
        for(int i = 0; i < n; i++){
            lastSeen[s[i] - 'a'] = i;
            //we have a b c 
            if(lastSeen[0]!= -1 && lastSeen[1]!= -1 && lastSeen[2]!= -1){
                //all substr from front that can be formed with curr substr
                int mini = min(lastSeen[2], min(lastSeen[1], lastSeen[0]));
                cnt = cnt + 1 + mini;
            } 
        }
        return cnt;
    }
    TC = O(N), SC =O(1)