// First generate all permutations and sort them
// Find current permuation index using linear search
// If index is lastin order then return first permutation else return next in order
//public:
//     void nextPermutation(vector<int>& nums) {
//         vector<vector<int>> ans = genAllPermutation(nums);
//         int index = -1;
//         for(int i = 0; i < ans.size(); i++){
//             if(nums == ans[i]){
//                 index = i;
//                 break;
//             }
//         }
//         if(index == ans.size() - 1) nums = ans[0];
//         else nums = ans[index + 1];
//         return;
//     }
// private:
// //function to create all permutation in sorted order
//     vector<vector<int>> genAllPermutation(vector<int>& nums){
//         vector<vector>> ans;
//         func(0, nums, ans); //recursive func to recall
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// //helper func to get all permutation of given array
//     void func(int ind, vector<int>& nums, vector<vector<int>>& ans){
//         if(ind == nums.size()){
//             ans.push_back(nums);
//             return;
//         }
//         for(int i = ind; i < nums.size(); i++){
//             swap(nums[ind], nums[i]);
//             func(ind + 1, nums, ans);
//             swap(nums[ind], nums[i]);
//         }
//         return; 
//     }
//     TC = O(N * N!), SC = O(N *N!)
----------------------------------------------------------------------
    // void nextPermutation(vector<int>& nums) {
    //     int n = nums.size();
    //     int index =-1;
    //     //find index of first smaller element from right
    //     for(int i = n - 2; i >= 0; i--){
    //         if(nums[i] < nums[i +1]){
    //             index = i;
    //             break;
    //         }
    //     }
    //     if(index == -1){
    //         reverse(nums.begin(), nums.end());
    //         return;
    //     }
    //     //find element just greater then nums[ind] from end
    //     for(int i = n - 1; i > index; i--){
    //         if(nums[i] > nums[index]){
    //             swap(nums[i], nums[index]);
    //             break;
    //         }
    //     }
    //     //reverse the right half to get next smaller permutation
    //     reverse(nums.begin()+ index + 1, nums.end());
    //     return;
    // }
    // TC = O(N), SC = O(1)