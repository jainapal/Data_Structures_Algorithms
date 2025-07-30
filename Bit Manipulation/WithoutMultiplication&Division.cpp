    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;

        bool isPositive = true;
        if(divisor < 0 && dividend >= 0) isPositive = false;
        else if(dividend < 0 && divisor > 0) isPositive = false;

        long long n = abs(dividend);
        long long d = abs(divisor);

        long long ans = 0, sum = 0;
        while(sum + d <= n){
            ans ++;
            sum += d;
        }
        if(ans > INT_MAX && isPositive) return INT_MAX;
        if(ans > INT_MAX && !isPositive) return INT_MIN;

        return isPositive ? ans : -1 * ans;
    }
    TC = O(Divident), SC = O(1)
------------------------------------------------------------------------------
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(divisor == 1) return dividend;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool isPositive = true;
        if(dividend >= 0 && divisor < 0) isPositive = false;
        if(dividend < 0 && divisor > 0) isPositive = false;

        long n = abs(dividend);
        long d = abs(divisor);

        int ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt + 1) )){
                cnt++;
            }
            ans += 1 << cnt;
            n = n - (d << cnt);
        }
        if(ans == (1 << 31) && isPositive) return INT_MAX;
        if(ans == (1 << 31) && !isPositive) return INT_MIN;

        return isPositive ? ans : -1 * ans;
    }
    TC = O((LogN) ^ 2), SC = O(1)