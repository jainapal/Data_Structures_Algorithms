vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
        int n = Intervals.size();
        int i = 0;
        vector<vector<int>> ans;
        //add intervals before new interval
        while(i < n && Intervals[i][1] < newInterval[0]){
            ans.push_back(Intervals[i]);
            i++;
        }
        //merge overlapping intervals with new interval
        while(i < n && Intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], Intervals[i][0]);
            newInterval[1] = max(newInterval[1], Intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        //add all remaining intervals
        while(i < n){
            ans.push_back(Intervals[i]);
            i++;
        }

        return ans;
    }
    TC = O(N), SC = O(N)

    Q How would you modify solution to return overlapping interval instead of inserting?

    vector<vector<int>> getOverlappingIntervals(vector<vector<int>>& Intervals, vector<int>& newInterval) {
    vector<vector<int>> overlapping;
    int start = newInterval[0], end = newInterval[1];

    for (auto& interval : Intervals) {
        int s = interval[0], e = interval[1];
        if (e >= start && s <= end) {
            overlapping.push_back(interval);
        }
    }

    return overlapping;
}
TC = O(N), O(K), K is the number of overlapping interval