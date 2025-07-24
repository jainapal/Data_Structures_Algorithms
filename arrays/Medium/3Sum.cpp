    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<vector<int>> s;
    //     int n = nums.size();

    //     for(int i = 0; i < n-2; i++){
    //         for(int j = i + 1; j < n-1; j++){
    //             for(int k = j + 1; k < n; k++){
    //                 if(nums[i]+nums[j]+nums[k] == 0){
    //                     vector<int> temp = {nums[i],nums[j],nums[k]};
    //                     sort(temp.begin(), temp.end());
    //                     s.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    //     vector<vector<int>> ans(s.begin(),s.end());
    //     return ans;
    // }
    // TC = O(N^3),SC = O(2 * No. of unique triplets)

--------------------------------------------------------------------------------
// vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> s;
//         int n = nums.size();

//         for(int i = 0; i < n-1; i++){
//             set<int> hashset;
//             for(int j = i + 1; j < n; j++){
//                 int req = -(nums[i] + nums[j]);
//                 if(hashset.find(req) != hashset.end()){
//                     vector<int> temp = {nums[i],nums[j], req};
//                     sort(temp.begin(), temp.end());
//                     s.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         vector<vector<int>> ans(s.begin(),s.end());
//         return ans;
//     }
//     TC = O(N^2 + LOG(unique triplets)) , insert in set takes logN
//     SC = O(2 * UNIQUE TRPLETS) + O(N);
-----------------------------------------------------------------------------------------
// vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < n; i++){
//             //to handle duplicates
//             if(i > 0 && nums[i] == nums[i-1]) continue;

//             int j = i + 1, k = n - 1;
//             while(j < k){
//                 int sum = nums[i] + nums[j] + nums[k];
//                 if(sum < 0 ) j++;
//                 else if(sum > 0) k--;
//                 else{
//                     ans.push_back({nums[i],nums[j],nums[k]});
//                     j++, k--;
//                     while(j < k && nums[j] == nums[j-1]) j++;
//                     while(j < k && nums[k] == nums[k+1]) k--;
//                 }
//             }
//         }
//         return ans;
//     }
//     TC = O(NLOGN + N^2), SC = O(1)