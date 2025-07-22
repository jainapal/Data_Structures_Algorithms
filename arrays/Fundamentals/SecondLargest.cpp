
// int secondLargestElement(vector<int>& arr){
//     if(nums.size() < 2) return -1;
//     int largest = INT_MIN, secondLargest = INT_MIN;
//     for(int i = 0; i < n; i++){
//         if(arr[i] > largest){
//             secondLargest = largest;
//             largest = arr[i];
//         }
//         else if(arr[i] > secondlargest && arr[i] != largest){
//             secondlargest = arr[i];
//         }
//     }
//     return (secondlargest == INT_MIN) ? -1 : secondlargest;
// }
// TC = O(N), SC = O(1)