// void rotateByK(vector<int>& arr){
//     int n = arr.size();
//     k = k % n;
//     vector<int> temp;
//     for(int i = 0; i < k; i++){
//         temp.push_back(arr[i]);
//     }
//     for(int i = k; i < n; i++){
//         arr[i - k] = arr[i];
//     }
//     for(int i = 0; i < k; i++){
//         nums[n - k + i] = temp[i];
//     }
// }
// TC = O(N), SC = O(K)

// ------------------------------------------------------------
// void rotateArray(vector<int>& nums, int k) {
//         if(k>nums.size()) k=k%nums.size();
//         reverse(nums.begin(),nums.begin()+k);
//         reverse(nums.begin()+k,nums.end());
//         reverse(nums.begin(),nums.end());
//         return;
// }
// TC = O(N), SC = O(1)

// ------------------------------------------------------------------
// upper one is for left rotate i,e puttion first element to last
// but what if we have to do right rotate i,e puttion last elemnt to first

// void rotateArray(vector<int>& nums, int k) {
//         if(k>nums.size()) k=k%nums.size();
//         reverse(nums.begin(),nums.end());
//         reverse(nums.begin(),nums.begin()+k);
//         reverse(nums.begin()+k,nums.end());
//         return;
//     }