// vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> pos;
//         vector<int> neg;
//         int n = nums.size();
//         vector<int> ans(n);
//         int first = nums[0];
//         for(int i : nums){
//             if(i < 0) neg.push_back(i);
//             else{
//                 pos.push_back(i);
//             }
//         }
//         for(int i = 0; i < n/2; i++){
//             ans[2*i] = pos[i];
//             ans[i*2 + 1] = neg[i];
//         }
//         return ans;
//     }
//     TC = O(N + N), SC = O( N/2 + N/2 + N)

// ------------------------------------------------------------------------
//    vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         int pos = 0, neg = 1;
//         for(int i = 0; i < n; i++){
//             if(nums[i] < 0){
//                 ans[neg] = nums[i];
//                 neg+=2;
//             }
//             else{
//                 ans[pos] = nums[i];
//                 pos += 2;
//             }
//         }
//         return ans;
//     }
//     TC = O(N), SC = O(N)

