// int maximumUniqueSubarray(vector<int>& nums) {
//         int n = nums.size();
//         unordered_set<int> freq;
//         int maxscore = 0, currscore = 0;
//         int left = 0;
//         for(int right = 0; right < n; right++){
//             int num = nums[right];
            
//             while(freq.find(num) != freq.end()){
//                 freq.erase(nums[left]);
//                 currscore -= nums[left];
//                 left++;
//             }
//             freq.insert(num);
//             currscore += num;
//             maxscore = max(maxscore, currscore);
//         }

//         return maxscore;
//     }
//     TC = O(N), SC = O(1)