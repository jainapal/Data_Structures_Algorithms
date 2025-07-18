/*
TC = O(Log(n) + k), SC = K

class Solution {
private:
    int lowerBound(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                high = mid - 1;
                ans = mid;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int j = lowerBound(arr, x);
        //int j = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = j - 1;

        while (k > 0) {
            if (i < 0) {
                j++;
            } else if (j >= n) {
                i--;
            } else if (x - arr[i] <= arr[j] - x) {
                i--;
            } else {
                j++;
            }
            k--;
        }

        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};

---------------------------------MIN HEAP -----------------------------------------------
TC = O(nLogk), SC = O(K);

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>> maxHeap;
        for(int num : arr){
            maxHeap.push({abs(num - x), num});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<int> ans;
        while(maxHeap.size() != 0){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

---------------------------------Sliding Window----------------------------------------------
TC = O(N - K), SC = O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;

        while((right - left + 1) > k){
            if(x - arr[left] <= arr[right] - x) right--;
            else left++;
        }
        return vector<int> (arr.begin() + left, arr.begin() + right + 1);
    }
};

*/