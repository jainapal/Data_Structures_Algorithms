vector<int> primeFact(int n){
            vector<int> ans;
            while(n % 2 == 0){
                ans.push_back(2);
                n = n / 2;
            }
            //iterating from 3 skip one number coz is odd now
            for(int i = 3; i <= sqrt(n); i+=2){
                while(n % i == 0){
                    ans.push_back(i);
                    n = n / i;
                }
            }
            if(n > 2) ans.push_back(n);
            return ans;
        }
        vector<vector<int>> primeFactors(vector<int>& queries){
            vector<vector<int>> ans;
            for(int i = 0; i < queries.size(); i++){
                ans.push_back(primeFact(queries[i]));
            }
            return ans;
        }
        TC = O(size) + O(sqrt(size)), SC = O(N * Log(num))

-----------------------------------------------------------------------------
class Solution {
public:
    static const int MAX_N = 100000;
    vector<int> SPF;
    bool built;

    Solution() : SPF(MAX_N + 1), built(false) {}

    void seive() {
        for (int i = 0; i <= MAX_N; i++) SPF[i] = i;
        for (int i = 2; i * i <= MAX_N; i++) {
            if (SPF[i] == i) {
                for (int j = i * i; j <= MAX_N; j += i) {
                    if (SPF[j] == j) SPF[j] = i;
                }
            }
        }
        built = true;
    }

    vector<int> primeFact(int n) {
        vector<int> ans;
        while (n != 1) {
            ans.push_back(SPF[n]);
            n /= SPF[n];
        }
        return ans;
    }

    vector<int> primeFactUnique(int n) {
        vector<int> ans;
        while (n != 1) {
            int p = SPF[n];
            ans.push_back(p);
            while (n % p == 0) n /= p;
        }
        return ans;
    }

    vector<vector<int>> primeFactors(vector<int>& queries) {
        if (!built) seive();
        vector<vector<int>> ans;
        for (int q : queries) {
            ans.push_back(primeFact(q)); // or primeFactUnique(q)
        }
        return ans;
    }
};

TC = O(Nlog(log N) + logN + QlogM), Q is no. of queries, N is MAX_N and M is max query value
SC = O(N + logN + total factors)