int trap(vector<int> &height){
        int n = height.size();
        int amt = 0, i = 0;
        while(i < n){
            int left = height[i];
            int nextHigh = -1, nextInd = -1;
            int rem = 0;
            for(int j = i + 1; j < n; j++){
                if(height[j] >= left){
                    nextHigh = height[j];
                    nextInd = j;
                    break;
                }
                if(height[j] > nextHigh){
                    nextHigh = height[j];
                    nextInd = j;
                }
            }
            if(nextInd == -1) break;
            int minHeight = min(left, nextHigh);
            for(int k = i + 1; k < nextInd; k++){
                amt += max(0,minHeight - height[k]);
            }
            i = nextInd;
        }
        return amt;
    }
    TC = O(N^2), SC = O(1)
---------------------------------------------------------------------
vector<int> findPrefixMax(vector<int>& arr, int& n){
        vector<int> prefixMax(n);
        prefixMax[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }
        return prefixMax;
    }
    vector<int> findSuffixMax(vector<int>& arr, int& n){
        vector<int> suffixMax(n);
        suffixMax[n - 1] = arr[ n -1];
        for(int i = n - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }
        return suffixMax;
    }
    int trap(vector<int> &height){
        int n = height.size();
        int ans = 0;
        vector<int> leftMax = findPrefixMax(height, n);
        vector<int> rightMax = findSuffixMax(height, n);

        for(int i = 0; i < n; i++){
            if(leftMax[i] > height[i] && rightMax[i] > height[i]){
                ans += min(leftMax[i], rightMax[i]) - height[i];
            }
        }
        return ans;
    }
    TC = O(N + N + N) , SC = O(N + N)
---------------------------------------------------------------------------------------------
vector<int> findSuffixMax(vector<int>& arr, int& n){
        vector<int> suffixMax(n);
        suffixMax[n - 1] = arr[ n -1];
        for(int i = n - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }
        return suffixMax;
    }
    int trap(vector<int> &height){
        int n = height.size();
        int ans = 0;
        int leftMax = height[0];
        vector<int> rightMax = findSuffixMax(height, n);

        for(int i = 1; i < n; i++){
            leftMax = max(leftMax, height[i]);
            int waterlevel = min(leftMax, rightMax[i]);
            if(waterlevel > height[i]){
                ans += waterlevel - height[i];
            }
        }
        return ans;
    }
    TC = O(2N), SC = O(N)
------------------------------------------------------------------------------------------
int trap(vector<int> &height){
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0;
        int leftmax = 0, rightmax = 0;
        while(i < j){
            if(height[i] <= height[j]){
                //if water can be stored
                if(leftmax > height[i]){
                    ans += leftmax - height[i];
                }
                else leftmax = height[i];
                i++;
            }
            else{
                //if water can be stored
                if(rightmax > height[j]){
                    ans += rightmax - height[j];
                }
                else rightmax = height[j];
                j--;
            }
        }
        return ans;
    }
    TC = O(N), SC = O(1)