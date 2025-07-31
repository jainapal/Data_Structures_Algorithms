    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        long long wt = 0;
        for(int i = 0; i < n - 1; i++){
            wt += (bt[i] *(n - i - 1));
        }
        long long ans = wt / n;
        return ans;
    }
    TC = O(NLOGN + N), SC = O(1)

Q How would you extend this to include arrival time?
long long solve(vector<int>& arrival, vector<int>& burst) {
    int n = arrival.size();

    using P = pair<int, int>; // {burst, arrival}
    vector<tuple<int, int, int>> processes;

    for (int i = 0; i < n; ++i) {
        processes.emplace_back(arrival[i], burst[i], i);
    }

    sort(processes.begin(), processes.end());

    priority_queue<P, vector<P>, greater<P>> minHeap;

    long long time = 0, i = 0, totalWT = 0;

    while (i < n || !minHeap.empty()) {
        while (i < n && get<0>(processes[i]) <= time) {
            minHeap.emplace(get<1>(processes[i]), get<0>(processes[i]));
            ++i;
        }

        if (!minHeap.empty()) {
            auto [burst, arrivalTime] = minHeap.top(); minHeap.pop();
            totalWT += time - arrivalTime;
            time += burst;
        } else {
            time = get<0>(processes[i]);
        }
    }

    return totalWT / n;
}
