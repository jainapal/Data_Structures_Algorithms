    int findRangeXOR(int l,int r){
        int ans = 0;
		for(int i = l; i <= r; i++){
            ans = ans ^ i;
        }
        return ans;
	}
    TC = O(N), SC = O(1)
--------------------------------------------------------
    int findRangeXOR(int l,int r){
            return XORtillN(l-1) ^ XORtillN(r);
		}
        
    int XORtillN(int n){
        if(n % 4 == 1) return 1;  
        if(n % 4 == 2) return n + 1;   
        if(n % 4 == 3) return 0; 
        if(n % 4 == 0) return n;  
    }
    TC = O(1), SC = O(1)