bool isPrime(int n){
            int cnt = 0; //cnt of divisors of n
            for(int i = 1; i <= sqrt(n); i++){
                //i is a divisor
                if(n % i == 0){
                    cnt++;
                    //counterpart divisior is different from original divisor
                    if(n / i != i) cnt++;
                }
            }
            if(cnt == 2) return true;
            return false;
        }
        vector<int> primeTillN(int n){
            vector<int> primes;
            for(int i = 2; i <= n; i++){
                if(isPrime(i)){
                    primes.push_back(i);
                }
            }
            return primes;
        }

        TC = O(n) + O(sqrt(n)), SC = O(N)
------------------------------------------------------------------------------
vector<int> primeTillN(int n){
            vector<int> isPrime(n + 1, 1);
            vector<int> ans;
            for(int i = 2; i <= n; i++){
                if(isPrime[i] == 1){
                    ans.push_back(i);
                    for(long long j = (long long)i * i; j <= n; j += i){
                        isPrime[j] = 0;
                    }
                }
            }
            return ans;
        }
        TC = O(N) + O(NLog(LogN)), SC = O(N)