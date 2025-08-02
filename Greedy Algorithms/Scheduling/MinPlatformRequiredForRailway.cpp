int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        int n = Arrival.size();
        int platform = 1;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            int start = Arrival[i];
            int end = Departure[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (start >= Arrival[j] && Departure[j] >= start) {
                        cnt++;
                    }
                    platform = max(platform, cnt);
                }
            }
            
        }
        return platform;
    }
    TC = O(N^2), SC = O(1)
----------------------------------------------------------------------------------------
int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();

        vector<pair<int, int>> trains(n);
        for (int i = 0; i < n; i++) {
            trains[i] = {Arrival[i], Departure[i]};
        }
        sort(trains.begin(), trains.end());

        priority_queue<int, vector<int>, greater<int>> minheap;
        minheap.push(trains[0].second);
        int platform = 1;

        for(int i = 1; i < n; i++){
            // If current train arrives after the earliest train departs, reuse platform
            while(!minheap.empty() && trains[i].first > minheap.top()){
                minheap.pop();
            }
            // Always push current train’s departure
            minheap.push(trains[i].second);
            platform = max(platform, (int)minheap.size());
        }
        return platform;
    }
    TC = O(NLOGN), SC = O(N)
---------------------------------------------------------------------------------------------
int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int i = 1, j = 0;
        int cnt = 1, platform = 1;

        while(i < n && j < n){
            //train arrive before earliest train departed
            if(Arrival[i] <= Departure[j]){
                cnt++;
                i++;
            }
            //train has departed and a platform is free
            else{
                cnt--;
                j++;
            }
            platform = max(platform, cnt);
        }
        return platform;
    }
    TC = O(Nlogn), SC = O(1)