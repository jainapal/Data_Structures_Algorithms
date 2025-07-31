static bool compare(const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second; //sort by ending time
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n = start.size();
        vector<pair<int,int>> meetings;
        for(int i = 0; i < n; i++){
            meetings.push_back({start[i], end[i]});
        }
        sort(meetings.begin(), meetings.end(), compare);

        int lastend = meetings[0].second;
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(meetings[i].first > lastend){
                lastend = meetings[i].second;
                cnt++;
            }
        }
        return cnt;
    }
    TC = N(LOGN + N), SC = O(N)

    Q what if there are multiple meeting rooms 

    int maxMeetingsWithKRooms(vector<int>& start, vector<int>& end, int k) {
    int n = start.size();
    vector<pair<int, int>> meetings;

    for(int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i]});
    }

    // Sort meetings by start time
    sort(meetings.begin(), meetings.end());

    // Min-heap to store end times of occupied rooms
    priority_queue<int, vector<int>, greater<int>> pq;

    int count = 0;

    for(auto& m : meetings) {
        int startTime = m.first;
        int endTime = m.second;

        // Free up rooms that have ended before current start
        while(!pq.empty() && pq.top() <= startTime) {
            pq.pop();
        }

        if(pq.size() < k) {
            // Assign meeting to a room
            pq.push(endTime);
            count++;
        }
        // Else, all rooms are occupied — skip meeting
    }

    return count;
}
TC = O(NLOGN + NLOGK), SC = O(N)