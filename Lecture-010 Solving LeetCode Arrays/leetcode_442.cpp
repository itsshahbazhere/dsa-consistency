// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int>duplicate(nums.size()+1,0);
        for(int i=0; i<nums.size(); i++){
            int index = nums[i];
            duplicate[index]++;
        }

        nums.clear();
        for(int i=0; i<duplicate.size(); i++){
            if(duplicate[i] == 2){
                nums.push_back(i);
            }
        }

        return nums;
        
    }
};