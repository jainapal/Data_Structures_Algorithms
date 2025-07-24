// vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i, j};
//                 }
//             }
//         }
//         return {-1,-1};
//     }
// TC = O(N^2), SC = O(1)
// -------------------------------------------------------------------
// vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int,int> mp;
//         for(int i = 0; i < n; i++){
//             int req = target - nums[i];
//             if(mp.find(req) != mp.end()){
//                 return {mp[req], i};
//             }
//             mp[nums[i]] = i;
//         }
//         return {-1,-1};
// }
// TC = O(N), SC = O(N)

--------------------------------------------------------------------
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     vector<vector<int>> ind;
    //     for(int i =0; i < n; i++){
    //         ind.push_back({nums[i], i});
    //     }
    //    //This is a custom comparator. It tells sort to compare a[0], i.e., the number (not the index).
    //     sort(ind.begin(), ind.end(),[](const vector<int>& a, const vector<int>& b){
    //         return a[0] < b[0];
    //     });

    //     int i =0, j = n-1;
    //     while(i < j){
    //         //ind[i][0] gives you the first element in that row → the value from nu
    //         int sum = ind[i][0] + ind[j][0];

    //         if(sum == target){
    //             //ind[i][1] gives you the second element in that row → the original index in nums.
    //             return {ind[i][1], ind[j][1]};
    //         }
    //         else if(sum > target) j--;
    //         else i++;
    //     }
    //     return {-1,-1};
    // }
    // TC = O(NLOGN), SC = O(N);