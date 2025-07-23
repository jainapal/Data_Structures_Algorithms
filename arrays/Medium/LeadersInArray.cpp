// vector<int> leaders(vector<int>& nums) {
//       int n = nums.size();
//       vector<int> ans;
      
//       for(int i = 0; i < n; i++){
//         bool leader = true;
//         for(int j = i+1; j < n; j++){
//             if(nums[j] > nums[i]){
//                 leader = false;
//                 break;
//             }
//         }
//         if(leader == true) ans.push_back(nums[i]);
//       }
//       return ans;
//     }
//     TC = O(N^2), SC = O(1)
// -------------------------------------------------------------------
// vector<int> leaders(vector<int>& nums) {
//       int n = nums.size();
//       vector<int> ans;
//       if(nums.empty()) return ans;
//       int rightmostmax = nums[n-1];
//       for(int i = n-1; i>= 0; i--){
//         if(i == n-1) ans.push_back(nums[i]);
//         if(nums[i] > rightmostmax){
//             ans.push_back(nums[i]);
//             rightmostmax = nums[i];
//         }
//       }
//       reverse(ans.begin(), ans.end());
//       return ans;
//     }
//     TC = O(N), SC = O(1)