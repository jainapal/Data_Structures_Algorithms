int longestNonRepeatingSubstring(string& s){
        int n = s.length();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            vector<int> hash(256, 0);
            for(int j = i; j < n; j++){
                if(hash[s[j]] == 1) break;
                hash[s[j]] = 1;
                int len = j - i + 1;
                maxlen = max(maxlen , len);

            }
        }
        return maxlen;
    }
    TC = O(N^2), SC = O(1)
--------------------------------------------------------------------------------
int longestNonRepeatingSubstring(string& s){
        int n = s.length();
        int maxlen = 0;
        int l = 0, r = 0;
        vector<int> hash(256, 0); //storing index of char in window

        while(r < n){
            if(hash[s[r]] != 0){
                //move left pointer to right of last occurence
                l = max(hash[s[r]] + 1, l);
            }
            int len = r - l + 1;
            maxlen = max(maxlen , len);
            hash[s[r]] = r; //store ind of curr char in hash table
            r++;
        }
        return maxlen;
    }
    TC = O(N), SC = O(1);