// int missingNumber(vector<int>& nums) {
//         int n = nums.size();
        
//         for(int i = 0; i <= n ; i++){
//             bool flag = false;
//             flag = linearsearch(i, nums);
//             if(!flag) return i;
//         }
//         return -1;
//     }
//     bool linearsearch(int num, vector<int>& nums){
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == num){
//                 return true;
//             }
//         }
//         return false;
//     }
//     TC = O(N^2), SC = O(1)

-------------------------------------------------------------------
// int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int freq[n + 1] = {0};
//         for(int i = 0; i < n; i++){
//             freq[nums[i]]++;
//         }
//         for(int i = 0; i <= n; i++){
//             if(freq[i] == 0) return i;
//         }
//         return -1;
// }
// TC = O(N), SC = O(N)

-------------------------------------------------------
int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        for(int i = 0; i< n; i++){
            sum1 += nums[i];
        }
        int sum2 = (n * (n + 1))/2;

        return sum2 - sum1;
}
TC = O(N), SC = O(1)
-----------------------------------------------------------
// int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int xorr = 0;
//         for(int i = 0; i < n; i++){
//             xorr ^= i;
//             xorr ^= nums[i];
//         }
//         xorr ^= n;
//         return xorr;
// }
// TC = O(N), SC = O(1);