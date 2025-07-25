long long int numberOfInversions(vector<int> nums) {
    int cnt = 0;
    int n = nums.size();
    for(int i = 0; i < n -1; i++){
        for(int j =  i + 1; j < n; j++){
            if(nums[i] > nums[j]) cnt++;
        }
    }
    return cnt;
}
TC = O(N^2), SC = O(1)
---------------------------------------------------------------
private:
   long long int merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    long long int cnt=0;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            cnt+=mid-left+1;
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
    for(int i=low;i<=high;i++) nums[i] = temp[i-low];
    return cnt;
   }

   long long int mergesort(vector<int>& nums,int low,int high){
    long long int cnt=0;
    if(low<high){
        int mid= low + (high-low)/2;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,high);
        cnt+=merge(nums,low,mid,high);
    }
    return cnt;
   }
public:
   long long int numberOfInversions(vector<int> nums) {
    int n=nums.size();
    return mergesort(nums,0,n-1);
    }

TC = O(NLOGN), SC = O(N);