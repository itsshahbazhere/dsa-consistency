// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int>temp(nums.size());
        int pos = 0;
        int neg = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                temp[pos] = nums[i];
                pos+=2;
            }
            else{
                temp[neg] = nums[i];
                neg+=2;
            }
        }
        return temp;
        
    }
};