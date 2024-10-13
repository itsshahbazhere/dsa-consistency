// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/ 

class Solution {
public:
    int minElement(vector<int>& nums) {
        
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int sum =0;
            //int n = nums[i];
            while(nums[i]!=0){
                int lastDigit = nums[i]%10;
                sum+=lastDigit;
                nums[i] = nums[i]/10;
            }
            ans.push_back(sum);
        }

        int mini = INT_MAX;
        for(int i=0;i<ans.size(); i++){
            mini = min(mini,ans[i]);
        }

        return mini;
    }
};