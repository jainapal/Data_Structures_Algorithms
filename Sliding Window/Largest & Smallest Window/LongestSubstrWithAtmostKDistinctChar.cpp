int kDistinctChar(string& s, int k) {
        int n = s.size();
        int maxlen = 0;
        
        for(int i = 0; i < n; i++){
            unordered_set<int> st;
            for(int j = i; j < n; j++){
                st.insert(s[j]) ;
                if(st.size() <= k){
                    maxlen = max(maxlen, j - i + 1);
                }
                else break;
            }
        }
        return maxlen;
    }
    TC = O(N ^ 2), SC =O(K);
---------------------------------------------------------------------------------------
int kDistinctChar(string& s, int k) {
        int n = s.size();
        int maxlen = 0;
        unordered_map<int,int> mp;
        int l = 0;
        
        for(int i = 0; i < n; i++){
            mp[s[i]]++ ;
            if(mp.size() <= k){
                maxlen = max(maxlen, i - l + 1);
            }
            else{
                mp[s[l]]-- ;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
        
        }
        return maxlen;
    }
    TC = O(N), O(K);