// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {


        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi,nums[i]);
        }

        int index;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == maxi){
                index = i;
                continue;
            }
            if(maxi < nums[i]*2){
                return -1;
            }
        }

        return index;
        
    }
};