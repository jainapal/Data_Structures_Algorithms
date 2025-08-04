bool containsAll(int tFreq[], int windowFreq[]) {
        for (int i = 0; i < 128; i++) {
            if (tFreq[i] > windowFreq[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return "";

        int tFreq[128] = {0};
        for (char c : t) tFreq[c]++;

        int minlen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            int windowFreq[128] = {0};
            for (int j = i; j < n; j++) {
                windowFreq[s[j]]++;
                if (containsAll(tFreq, windowFreq)) {
                    int window = j - i + 1;
                    minlen = min(minlen, window); 
                    ans = s.substr(i, window);
                    break;  //break only after a valid window is found
                }
            }
        }

        return ans;
    }
    TC = O(N ^ 2) , SC = O(128 + 128 + N)
------------------------------------------------------------------------------------------------
string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return "";

        int tFreq[128] = {0};
        for (char c : t) tFreq[c]++;

        int minlen = INT_MAX;
        int l = 0, cnt = 0, sIndex = -1;

        for (int i = 0; i < n; i++) {
            if(tFreq[s[i]] > 0) cnt++;
            tFreq[s[i]]--;

            while( cnt == m){
                if(i - l + 1 < minlen){
                    minlen = i - l + 1;
                    sIndex = l;
                }
                //remove left most char from window
                tFreq[s[l]]++ ;
                if(tFreq[s[l]] > 0) cnt--;
                l++;
            }
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlen) ;
    }
    TC = O(2N + M), SC = O(128)