bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] >= n -1) return true;
        if(nums[0] == 0) return false;
        int reachable = 0;

        for(int i = 0; i < n; i++){
            if( i > reachable ) return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
    TC = O(N), SC = O(1)

Q what if you need to find minimum no. of jump to reach last index?
    int canJump(vector<int>& nums){
        int n = nums.size();
        int jump = 0, currend = 0, farthest = 0;

        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == currend){
                jump++;
                currend = farthest;
            }
        }
        return jump;
    }

Q what if we want to return indices of path taken?
    
    vector<int> minJumpPath(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return {0};

    vector<int> parent(n, -1); // to store where we came from
    int currEnd = 0; //curr range we cam reach before needing another jump
    int farthest = 0; // farthest index we can reach from curr jump range
    int bestNext = -1; // best index to jump from to extenf our reach

    for (int i = 0; i < n - 1; ++i) {
        if (i > farthest) break; // unreachable

        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
            bestNext = i; //from here i can go farthest right now
        }

        if (i == currEnd) {
            if (bestNext == -1) break;
            currEnd = farthest; //new range
            parent[currEnd] = bestNext; // jump from bestnext to currend
        }
    }

    if (parent[n - 1] == -1 && n > 1) {
        // We never reached the last index
        return {};
    }

    // Backtrack from end to start
    vector<int> path;
    int curr = n - 1;
    //Start from the last index (n - 1) and follow the trail backward using parent[].
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    
    path.push_back(0);
    reverse(path.begin(), path.end());
    return path;
}
