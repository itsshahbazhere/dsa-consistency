// https://leetcode.com/problems/increasing-triplet-subsequence/

// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int first_min = INT_MAX;
        int second_min = INT_MAX;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] <= first_min){
                first_min = nums[i];
            }
            else if(nums[i] <= second_min){
                second_min = nums[i];
            }
            else{
                return true;
            }
        }


        return false;
        
    }
};