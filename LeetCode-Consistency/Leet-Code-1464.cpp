// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int i=0;
        int j = nums.size()-1;
        int maxi = INT_MIN;
        
        while(i<j){
            
            int val = (nums[i]-1)*(nums[j]-1);
            maxi = max(maxi,val);
            if(nums[i] >= nums[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return maxi;
        
    }
};