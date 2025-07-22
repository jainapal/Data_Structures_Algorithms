// vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         set<int> s;
//         for(int i : nums1) s.insert(i);
//         for(int j : nums2) s.insert(j);
//         for(int num : s){
//             ans.push_back(num);
//         }
//         return ans;
        
        
//     }
//     TC = O(M+N(LOG(M+N))) inserting in set tages log(n) time
//     SC = O(M + N)

---------------------------------------------------------------------
// vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         int i = 0, j = 0;
//         while(i < nums1.size() && j < nums2.size()){
//             if(nums1[i] <= nums2[j]){
//                 if(ans.size() == 0 || ans.back() != nums1[i]){
//                     ans.push_back(nums1[i]);
//                 }
//                 i++;
//             }
//             else{
//                 if(ans.size() == 0 || ans.back() != nums2[j]){
//                     ans.push_back(nums2[j]);
//                 }
//                 j++;
//             }
//         }
//         while(i < nums1.size()){
//             if(ans.back() != nums1[i]){
//                 ans.push_back(nums1[i]);
//             }
//             i++;
//         }
//         while(j < nums2.size()){
//             if(ans.back() != nums2[j]){
//                 ans.push_back(nums2[j]);
//             }
//             j++;
//         }
//         return ans;
//     }
//     TC = O(M + N), SC = O(1)