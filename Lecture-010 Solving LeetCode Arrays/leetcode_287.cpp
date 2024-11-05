// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/description/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        vector<int>cnt(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            int index = nums[i];
            cnt[index]++;
        }

        for(int i=1;i<cnt.size(); i++){
            if(cnt[i] >= 2){
                return i;
            }
        }

        return -1;
    }
};