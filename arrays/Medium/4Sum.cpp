// 
-----------------------------------------------------------------------------
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>> s;
//         for(int i = 0; i < n-2; i++){
//             for(int j = i+ 1; j < n-1; j++){
//                 set<int> hashset;
//                 for(int k = j + 1; k < n; k++){
//                     int req = target - nums[i] - nums[j] - nums[k];
//                     if(hashset.find(req) != hashset.end()){
//                         if(req == nums[k]) continue;
//                         vector<int> temp = {nums[i], nums[j],nums[k], req};
//                         sort(temp.begin(), temp.end());
//                         s.insert(temp);
//                     }
//                     hashset.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>> ans(s.begin(), s.end());
//         return ans;
//     }
//     TC = O(N^3), SC = O(2 * QUADUPLETS) + O(N)
-----------------------------------------------------------------------------------
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>> ans;

    //     for(int i = 0; i < n; i++){
    //         if(i > 0 && nums[i] == nums[i-1]) continue;
    //         for(int j = i + 1; j < n; j++){
    //             if(j > i + 1 && nums[j] == nums[j-1]) continue;
    //             int k = j + 1;
    //             int l = n - 1;
    //             while(k < l){
    //                 long long sum = nums[i] +nums[j] +nums[k] +nums[l];
    //                 if(sum == target){
    //                     vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
    //                     ans.push_back(temp);
    //                     k++, l--;
    //                     while(k < l && nums[k] == nums[k-1]) k++;
    //                     while(k < l && nums[l] == nums[l + 1]) l--;
    //                 }
    //                 else if(sum < target) k++;
    //                 else l--;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    // TC = O(N ^ 3), SC = O(QUADUPLET)