    int minBitsFlip(int start, int goal) { 
        int cnt = 0;
        //find all the bits where start and goal differ 
        int xrr = (start ^ goal);
        //no of bits that differ 
        while(xrr != 0){
            xrr = xrr & xrr - 1;
            cnt++;
        }
        return cnt;
    }
    TC = O(no. of set bits), SC = O(1)

    int minBitsFlip(int start, int goal) { 
        int cnt = 0;
        int xorr = start ^ goal;
        while(xorr){
            cnt += xorr & 1; //one at rightmost place
            xorr = xorr >> 1; 
        }
        return cnt;
    }
    TC = O(LOG(start)), SC = O(1)