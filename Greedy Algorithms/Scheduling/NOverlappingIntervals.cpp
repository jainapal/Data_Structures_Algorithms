//here i am counting which one to remove
bool static compare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
        int n = Intervals.size();
        int cnt = 0;
        //sort on ending times
        sort(Intervals.begin(), Intervals.end(), compare);
        int end = Intervals[0][1];
        for(int i = 1; i < n; i++){
            if(Intervals[i][0] < end){
                cnt++;
                
            }
            else end = Intervals[i][1] ;
        }
        return cnt;
    }

    //here i am counting which one to keep
    static bool comparator(vector<int>& a, vector<int>& b){
      return a[1] < b[1];
    }
    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
      int n = Intervals.size();
        int cnt = 1;
        sort(Intervals.begin(), Intervals.end(), comparator);
        int end = Intervals[0][1];
        for(int i = 1 ; i < n; i++){
          if(Intervals[i][0] >= end){
            end = Intervals[i][1];
            cnt++;
          }
        }
        return n - cnt;
    }

    TC = O(NLOGN), SC = O(1)
