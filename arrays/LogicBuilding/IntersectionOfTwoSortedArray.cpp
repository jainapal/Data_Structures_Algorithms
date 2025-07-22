// vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> vis(nums2.size(), 0);
//         vector<int> ans;
//         for(int i = 0; i< nums1.size(); i++){
//             for(int j = 0; j<nums2.size(); j++){
//                 if(nums1[i] == nums2[j] && vis[j]== 0){
//                     ans.push_back(nums2[j]);
//                     vis[j] = 1;
//                     break;
//                 }
//                 else if(nums2[j] > nums1[i]) break;
//             }
//         }
//         return ans;
//     }

//     ORRRRR

//     vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
//     unordered_map<int, int> mp;
//     vector<int> ans;

//     for (int num : nums2) mp[num]++;

//     for (int num : nums1) {
//         if (mp[num] > 0) {
//             ans.push_back(num);
//             mp[num]--;
//         }
//     }
//     return ans;
// }

//     TC = O(N*M), SC = O(N)

----------------------------------------------------------------------
// vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0 , j = 0;
//         vector<int> ans;
//         while(i < nums1.size() && j < nums2.size()){
//             if(nums1[i] == nums2[j]){
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//             else if(nums1[i] < nums2[j]) i++;
//             else j++;
//         }
//         return ans;
//     }
//     TC = O(M + N), SC = O(1)