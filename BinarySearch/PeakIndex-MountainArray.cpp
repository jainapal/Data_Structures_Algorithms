/*
TC = O(LOGN), SC = O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size();

        while(low < high){
            int mid = (low + high) / 2;
            if(arr[mid] < arr[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
            
        }
        return low;
    }
};
*/


