/*
valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.

Return the length of the longest valid subsequence of nums.
modulo value should be 0 or 1
case 1 : even , even --> 0   (all even numbers)
case 2 : odd , even --> 0    (all odd numbers)
case 3 : even , odd --> 1    (even odd on alternate / alternate parity)
case 4 : odd , even --> 1

TC = O(N), SC = O(1)


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int evencnt = 0;
        int oddcnt = 0;
        int alternatecnt = 1;

        for(int &num : nums){
            if(num % 2 == 0){
                evencnt++;
            }
            else{
                oddcnt++;
            }
        }

        int parity = nums[0] % 2;
        for(int i = 0; i < n; i++){
            if((nums[i] % 2) != parity){
                alternatecnt++;
                parity = nums[i] % 2;
            }
        }
        return max(max(evencnt, oddcnt), alternatecnt);
    }
};



*/