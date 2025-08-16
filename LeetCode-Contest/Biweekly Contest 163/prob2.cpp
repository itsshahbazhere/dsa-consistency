// https://leetcode.com/problems/number-of-perfect-pairs/

#include<bits/stdc++.h>
using namespace std;

// approach - 1 (TLE not solved)
// T.C - O(n^2)
// S.C - O(1)

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {

        int n = nums.size();
        long long cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int a = nums[i];
                int b = nums[j];
                if(min(abs(a-b),abs(a+b))<=min(abs(a),abs(b)) && max(abs(a-b),abs(a+b))>=max(abs(a),abs(b))){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};