// https://leetcode.com/problems/bulb-switcher/


// T.C = O(1) S.C = O(1) --------- Approach 1
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};



// T.C = O(LogN) S.C = O(1) --------- Approach 2
class Solution {
public:
    int bulbSwitch(int n) {

        int ans;
        int s = 0;
        int e = n;
        long long mid = s+(e-s)/2;
        // return sqrt(n);

        while(s<=e){
            if(mid*mid == n){
                return mid;
            }
            else if(mid*mid < n){
                s = mid + 1;
                ans = mid;
            }
            else{
                e = mid - 1;
            }
            mid = s+(e-s)/2;
        }

        return ans;
    }
};