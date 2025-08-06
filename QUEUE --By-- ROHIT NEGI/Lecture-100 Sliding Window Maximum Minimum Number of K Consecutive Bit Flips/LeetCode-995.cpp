// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/


#include<bits/stdc++.h>



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