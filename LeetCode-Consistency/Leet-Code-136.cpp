// 136. Single Number
// https://leetcode.com/problems/single-number/description/


class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n= nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};