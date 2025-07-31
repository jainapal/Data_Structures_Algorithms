bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;

    for (int bill : bills) {
        if (bill == 5) five++;
        else if (bill == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        }
        else { // bill == 20
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            }
            else if (five >= 3) {
                five -= 3;
            }
            else return false;
        }
    }
    return true;
}
TC = O(N), SC = O(1)

Q what happens if customer allowed to pay with other denominations?
bool lemonadeChange(vector<int>& bills){
    int cost = 5;
    map<int,int, greater<int>> track; // denomination -> count, largest first
    for(int bill : bills){
        int change = bill - cost;
        // Try to give change using greedy largest denominations
        int rem = change;
        for(auto& [denom,_] : track){
            while(denom <= rem && track[denom] > 0){
                rem -= denom;
                track[denom]--;
            }
            if(rem == 0) break;
        }
        if(rem != 0) return false;
        // If change successfully given, add the current bill to track
        track[bill]++;
    }
    return true;
}
TC = O(N * D ~ N) , SC = 0(D), D is number of denominations