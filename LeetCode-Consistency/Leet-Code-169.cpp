// https://leetcode.com/problems/majority-element/

// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt=1, i=0;

        while(i<n){

            if(cnt>n/2) return nums[i];
            if(nums[i] == nums[i+1]) cnt++;
            else cnt=1;
            i++;
        }
        return -1;
    }
};