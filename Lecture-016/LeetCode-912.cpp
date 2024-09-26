// 912. Sort an Array
// link: https://leetcode.com/problems/sort-an-array/description/

/***************************** Time Limit Exceeded (selection sort) **************************************/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();

        for(int i=0; i<n-1; i++){

            int minIndex=i;

            for(int j=i+1; j<n; j++){
                
                if(nums[j] < nums[minIndex]){
                    minIndex = j;
                }
            }
            swap(nums[minIndex], nums[i]);
        }
        return nums;
    }
};