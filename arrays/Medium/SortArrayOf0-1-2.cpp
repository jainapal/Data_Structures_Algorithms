//     void sortZeroOneTwo(vector<int>& nums) {
//         int zero = 0, one = 0, two = 0;
//         for(int i = 0;i < nums.size(); i++){
//             if(nums[i] == 0) zero++;
//             if(nums[i] == 1) one++;
//             if(nums[i] == 2) two ++;
//         }
//         for(int i = 0; i < zero; i++) nums[i] = 0;
//         for(int i = zero; i< zero + one; i++) nums[i] = 1;
//         for(int i = zero + one; i < nums.size(); i++) nums[i] = 2;
//     }
//     TC + O(N + N)< SC + O(1)
// --------------------------------------------------------------------------------
//     void sortZeroOneTwo(vector<int>& nums) {
//         int n = nums.size();
//         int left = 0, mid = 0, right = n-1;
//         //0 to left - 1 contains 0
//         //left to mid - 1 contains 1
//         //mid to right containd mixed value i,e nums
//         //right + 1 to n-1 contains 2
//         while(mid <= right){
//             if(nums[mid] == 0){
//                 swap(nums[mid],nums[left]);
//                 left++;
//                 mid++;
//             }
//             else if(nums[mid] == 1){
//                 mid++;
//             }
//             else{
//                 swap(nums[mid], nums[right]);
//                 right--;
//             }
//         }
//     }
//     TC = O(N), SC = O(1)