/*
TC = O(NLOGN), SC = O(1)

class Solution {
private:
    int onecount(int num){
        int cnt = 0;
        for(int i = 0; i < 31; i++){
            if(num % 2 == 1) cnt++;
            num = num / 2;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int one = onecount(i);
            ans.push_back(one);
        }
        return ans;
    }
};

---------------------------------Optimal solution----------------------------------------

 TC = O(N), SC = O(N)

ans[i] = ans[i>>1] + (i&1)

i >> 1 → number i with its last bit removed.
(i & 1) → the last bit itself (1 if i is odd, 0 if even).
So the count of 1s in i = count of 1s in the number without its last bit + the last bit itself.

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i++){
            
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};



*/