int reversePairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > 2 * nums[j]) cnt++;
            }
        }
        return cnt;
}
TC = O(N^2), SC = O(1)
------------------------------------------------------------------------------------
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;
        int left=low, right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    int countpairs(vector<int>& nums, int low, int mid, int high){
        int right=mid+1, cnt=0;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>2*nums[right]) right++;
            cnt+=right-(mid+1);
        }
        return cnt;
    }
    int mergesort(vector<int>& nums, int low, int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid= low +(high-low)/2;
        cnt+= mergesort(nums,low,mid);
        cnt+= mergesort(nums,mid+1,high);
        cnt+= countpairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
        
    }

TC = O(2 * NLOGN), SC = O(N)