/*

We have to return first and smallest index whose value is 
greater than or equal to target

TC = O(LOG N), SC = O(1)



int lowerBound(vector<int>& arr, int target){
    int len = arr.size();
    int left = 0, right = len -1;
    int ans = arr.size();

    while(left <= right){
        int mid = left -(left - right)/2;
        if(arr[mid] < target){
            left = mid + 1;
        };
        else{
            ans = min(ans, arr[mid]);
            right = mid - 1;
        }
    }
    return ans;
}

*/