// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/


#include<bits/stdc++.h>

// Approach - 2 - OPTIMIZED SOLUTION;
// T.C - O(n);
// S.C - O(k);
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        queue<int>q;
        int flip = 0;

        for(int i=0; i<n; i++){

            if(!q.empty() && q.front()<i){
                q.pop();
            }
            if(q.size()%2==nums[i]){  //only this condition true then we will flip odd(1)-1, 0-even(0)
                if(i+k-1>=n){
                    return -1;
                }

                q.push(i+k-1);
                flip++;
            }
            
        }

        return flip;
    }       
};


// Approach - 1 - (by roghit negi);
// T.C - O(nk);
// S.C - O(1);

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        int flip = 0;

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(i+k>n){
                    return -1;
                }
                for(int j=i; j<i+k; j++){
                    nums[j] = !nums[j];
                }
                flip++;
            }
        }

        return flip;
    }
};



// Approach - 1 - (by me);
// T.C - O(nk);
// S.C - O(1);

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        int flip = 0;
        
        for(int i=0; i<=n-k; i++){
            if(nums[i]==0){
                for(int j=i; j<i+k; j++){
                    nums[j] = !nums[j];
                }
                flip++;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                return -1;
            }
        }

        return flip;
    }
};