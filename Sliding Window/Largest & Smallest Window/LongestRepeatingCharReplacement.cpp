int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            vector<int> freq(26,0);
            int maxfreq = 0;
            for(int j = i; j < n; j++){
                freq[s[j]-'A']++;
                maxfreq = max(maxfreq, freq[s[j] - 'A']);
                int window = j - i + 1;
                int change = window - maxfreq;
                if(change <= k){
                    maxlen = max(maxlen, window);
                }
                else break; 
            }
        }
        return maxlen;
    }
    TC = O(N ^2), SC = O(26)
-------------------------------------------------------------------------------------
int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0, maxfreq = 0;
        int l = 0;
        int hash[26] = {0};

        for(int i = 0; i < n; i++){
            hash[s[i] - 'A']++;
            maxfreq = max(maxfreq, hash[s[i] - 'A']);
            int change = (i - l + 1) - maxfreq;
            while(change > k){
                hash[s[l] - 'A']--;
                maxfreq = 0;
                for(int freq = 0; freq < 26; freq++){
                    maxfreq = max(maxfreq, hash[freq]);
                }
                l++;
                change = (i - l + 1) - maxfreq;
            }
            maxlen = max(maxlen, i - l + 1);
        }
        return maxlen;
    }
    TC = O(2N + 26), SC = O(26)
---------------------------------------------------------------------------------------
int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0, maxfreq = 0;
        int l = 0;
        int hash[26] = {0};

        for(int i = 0; i < n; i++){
            hash[s[i] - 'A']++;
            maxfreq = max(maxfreq, hash[s[i] - 'A']);
            int change = (i - l + 1) - maxfreq;
            if(change > k){
                hash[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, i - l + 1);
        }
        return maxlen;
    }
    TC = O(N), SC = O(26)