// https://leetcode.com/problems/minimum-sensors-to-cover-grid/

#include<bits/stdc++.h>
using namespace std;

// 2nd approach
// T.C - O(1)
// S.C - O(1)

class Solution {
public:
    int minSensors(int n, int m, int k) {

        // a = sensors required in rows
        // b = sensors required in cols
        // total sensors required c = a*b
        // return c
        return ceil((float)n/(2*k+1)) * ceil((float)m/(2*k+1));
    }
    
};


// 1st approach
// T.C - O(N)
// S.C - O(1)

class Solution {
public:
    int minSensors(int n, int m, int k) {

        int range = 2*k+1;
        int ans = 0;

        for(int i=1; i<=n; i++){
            if(range*i >= n){
                ans = i;
                break;
            }
        }

        int remHeight = m - 2*k - 1;
        if(remHeight<1){
            return ans;
        }
        else{
            for(int j=1; j<=m; j++){
                if(range*j>=remHeight){
                    ans = ans + ans*j;
                    break;
                }
            }
        }

        return ans;
    }
    
};