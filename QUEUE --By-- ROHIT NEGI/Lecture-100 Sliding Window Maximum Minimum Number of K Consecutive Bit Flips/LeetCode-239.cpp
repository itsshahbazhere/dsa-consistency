// https://leetcode.com/problems/sliding-window-maximum/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// Approach - 2
// T.C - O(n);
// S.C - O(n);

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>ans;
        deque<int>d;

        for(int i=0; i<k-1; i++){
            if(d.empty()){
                d.push_back(i);
            }
            else{
                while(!d.empty() && nums[d.back()]<nums[i]){
                    d.pop_back();
                }
                d.push_back(i);
            }
        }


        for(int i=k-1; i<n; i++){
            while(!d.empty() && nums[d.back()]<nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            while(i-k >= d.front()){
                d.pop_front();
            }
            ans.push_back(nums[d.front()]);
        }

        return ans;
    }
};


// Approach -1 TLE
// T.C - O(nk);
// S.C - O(n);

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        for(int i=0; i<=nums.size()-k; i++){
            int maxi = nums[i];
            for(int j=i; j<i+k; j++){
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};