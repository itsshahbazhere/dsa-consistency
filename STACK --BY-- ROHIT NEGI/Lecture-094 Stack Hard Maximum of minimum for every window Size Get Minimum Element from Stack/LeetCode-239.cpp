// https://leetcode.com/problems/sliding-window-maximum/

#include<bits/stdc++.h>
using namespace std;


// approach-1 TLE
// T.C - O(n^2)
// S.C - O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            int maxi = nums[i];
            int j = i;
            while(j<k+i && j<n){
                maxi = max(maxi,nums[j++]);
            }
            if(i+k<=n){
                ans.push_back(maxi);
            }
            
        }
        
        return ans;
    }
};


int main(){
    
    Solution obj;
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    obj.maxSlidingWindow(nums,3);

    for(int i=0;i<8;i++){
        cout<<nums[i]<<" ";
    }


}