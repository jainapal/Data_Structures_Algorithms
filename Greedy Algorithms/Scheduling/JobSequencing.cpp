    bool static compare(const vector<int>& a, const vector<int>& b) {
      return a[2] > b[2];
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        int n = Jobs.size();
        sort(Jobs.begin(), Jobs.end(), compare);

        int maxDeadline = -1;
        for(auto it : Jobs){
          maxDeadline = max(maxDeadline, it[1]);
        }
        vector<int> hash(maxDeadline + 1, -1);
        int cnt = 0, profit = 0;
        for(int i =0; i < n; i++){
          //iterate each deadline slot start from jobs deadline
          for(int j = Jobs[i][1]; j > 0; j--){
            if(hash[j] == -1){
              cnt++; //selected job
              hash[j] = Jobs[i][0]; //mark job as selected
              profit += Jobs[i][2];
              break; //move to next job;
            }
          }
        }
        return {cnt, profit};
    }
    TC = O(NLOGN + N^2), SC = O(maxdeadline)

  Q How would you handle jobs with more than 1 unit of duration

bool compare(const Job& a, const Job& b) {
  return a.profit > b.profit;
}

vector<int> JobScheduling(vector<Job>& Jobs) {
    sort(Jobs.begin(), Jobs.end(), compare);

    int maxDeadline = 0;
    for (auto& job : Jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<bool> slot(maxDeadline + 1, false); // 1-based indexing
    int totalProfit = 0, count = 0;

    for (auto& job : Jobs) {
        // Try to find a continuous block of 'duration' ending at or before deadline
        for (int end = job.deadline; end >= job.duration; end--) {
            bool canSchedule = true;
            for (int t = end - job.duration + 1; t <= end; t++) {
                if (slot[t]) {
                    canSchedule = false;
                    break;
                }
            }

            if (canSchedule) {
                for (int t = end - job.duration + 1; t <= end; t++)
                    slot[t] = true;
                totalProfit += job.profit;
                count++;
                break;
            }
        }
    }

    return {count, totalProfit};
}
