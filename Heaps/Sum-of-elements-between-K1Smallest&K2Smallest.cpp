class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        priority_queue<long long> p1;
        priority_queue<long long> p2;
        
        //insert k1 elements in p1
        for(long long i = 0; i < K1; i++){
            p1.push(A[i]);
        }
        //insert k2 elements in p2
        for(long long i = 0; i < K2 - 1; i++){
            p2.push(A[i]);
        }
        
        //Find k1 smallest elements in array
        for(int i = K1; i < N; i++){
            if(A[i] < p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }
        //Find k2 - 1 smallest elements in array
        for(int i = K2 - 1; i < N; i++){
            if(A[i] < p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }
        //sum of 1st max heap
        long long sum1 = 0, sum2 = 0;
        while(!p1.empty()){
            sum1 += p1.top();
            p1.pop();
        }
        //sum of 2nd max heap
        while(!p2.empty()){
            sum2 += p2.top();
            p2.pop();
        }
        
        return sum2 - sum1;
    }
};