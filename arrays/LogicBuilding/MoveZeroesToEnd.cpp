// void moveZeroes(vector<int>& nums){
//     int n = nums.size();
//     vector<int> temp;
//     for(int i = 0; i < n; i++){
//         if(nums[i] != 0){
//             temp.push_back(nums[i]);
//         }
//     }
//     int s = temp.size();
//     for(int i = 0; i < n; i++){
//         if(i < s){
//             nums[i] = temp[i];
//         }
//         else nums[i] = 0;
//     }
//     return;

// }
// TC = O(N), SC = O(N);
----------------------------------------------------

// void moveZeroes(vector<int>& nums) {
//         int n = nums.size() ;
//         int i = 0, j = -1;
//         while(i < n){
//             if(nums[i] == 0){
//                 j = i;
//                 break;
//             }
//             i++;
//         }
//         if(j == -1) return;
//         i = j + 1;
//         while(i < n){
//             if(nums[i] != 0){
//                 swap(nums[i], nums[j]);
//                 j++;
//             }
//             i++;
//         }

//     }

//     TC = O(N), SC = O(1)