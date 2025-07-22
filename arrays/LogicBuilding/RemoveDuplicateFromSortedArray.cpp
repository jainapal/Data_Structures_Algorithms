// int removeDuplicates(vector<int>& nums) {
//         set<int> s;
//         for(int i = 0; i < nums.size(); i++){
//             s.insert(nums[i]);
//         }
//         int k = s.size();

//         int j = 0;
//         for(int val : s){
//             nums[j++] = val;
//         }
//         return k;

// }
// TC = O(nlogn) for using set, SC = O(n)

-----------------------------------------------------------------------
// int removeDuplicates(vector<int>& nums) {
//         int i = 0, j = 1;
//         int n = nums.size();
//         while(j < n){
//             if(nums[i] != nums[j]){
//                 i++;
//                 nums[i] = nums[j];
                
//             }
//             j++;
//         }
//         return i + 1;
//     }
//     TC = O(N), SC = O(1)