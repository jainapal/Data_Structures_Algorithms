void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1, right = 0;
        while(left >= 0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--, right++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());

        for(int i = m; i < m + n; i++){
            nums1[i] = nums2[i - m];
        }
    }
    TC = 0(MLOGM + NLOGN + MIN(N,M)), SC = O(1)
-----------------------------------------------------------------------
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n + m;
        int gap = (len / 2) + (len % 2); // ceil value

        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                //left in nums1 and right in nums2
                if(left < m && right >= m && nums1[left] > nums2[right - m]){
                    swap(nums1[left], nums2[right - m]);
                }
                //both in nums1
                else if(left < m && right < m && nums1[left] > nums1[right]){
                    swap(nums1[left], nums1[right]);
                }
                //both in nums2
                else if(left >= m && right >= m && nums2[left-m] > nums2[right -m]){
                    swap(nums2[left - m], nums2[right - m]);
                }
                left++, right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2); //ceil value
        }
        //copy elements from nums2 to nums1
        for(int i = m; i < len; i++){
            nums1[i] = nums2[i - m];
        }
    }
    TC = O((M+N)LOG(M+N)), SC = O(1)