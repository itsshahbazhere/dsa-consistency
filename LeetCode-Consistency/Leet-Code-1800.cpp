// https://leetcode.com/problems/maximum-ascending-subarray-sum/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int sum = nums[0];
        int maxi = INT_MIN;

        if(nums.size() == 1){
            return sum;
        }

        for(int i=0; i<nums.size()-1; i++){
            
            if(nums[i] < nums[i+1]){
                sum += nums[i+1];
            }

            maxi = max(sum,maxi);

            if(nums[i] >= nums[i+1]){
                sum = nums[i+1];
            }            

        }

        return maxi;
        
    }
};


// test-case: 
// [5,5,6,6,6,9,1,2]
// [6]
// [100,10,1]